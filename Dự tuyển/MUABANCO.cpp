#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 2e5+10;
const ll MOD = 1e9+7;

int n, k, a[N], lmax[4*N], lmin[4*N];

void build(int x, int l, int r) {
    if(l == r) {
        lmax[x] = a[l];
        lmin[x] = a[l];
    }
    else {
        int mid = (l+r)/2;
        build(x*2, l, mid);
        build(x*2+1, mid+1, r);
        lmax[x] = max(lmax[x*2], lmax[x*2+1]);
        lmin[x] = min(lmin[x*2], lmin[x*2+1]);
    }
}

int get_max(int node, int l, int r, int x, int y) {
    if(l > y || r < x)
        return 0;
    if(l >= x && r <= y)
        return lmax[node];
    int mid = (l+r)/2;
    return max(get_max(node*2, l, mid, x, y), get_max(node*2+1, mid+1, r, x, y));
}

int get_min(int node, int l, int r, int x, int y) {
    if(l > y || r < x)
        return MOD;
    if(l >= x && r <= y)
        return lmin[node];
    int mid = (l+r)/2;
    return min(get_min(node*2, l, mid, x, y), get_min(node*2+1, mid+1, r, x, y));
}

void sub1() {
    build(1, 1, n);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, get_max(1, 1, n, i+1, n) - a[i]);
    }
    cout << ans;
}

void sub2() {
    build(1, 1, n);
    int ans = 0;
    for(int i = 2; i <= n-2; i++) {
        int mmin = get_min(1, 1, n, 1, i);
        if(mmin < i)
            ans = max(get_max(1, 1, n, mmin+1, i) - mmin, ans);
        int mmax = get_max(1, 1, n, 1, i);
        if(mmax > 1)
            ans = max(mmax - get_min(1, 1, n, 1, mmax-1), ans);
        //---------------
        int mmin = get_min(1, 1, n, i+1, n);
        if(mmin < n)
            ans = max(get_max(1, 1, n, mmin+1, n) - mmin, ans);
        int mmax = get_max(1, 1, n, i+1, n);
        if(mmax > i)
            ans = max(mmax - get_min(1, 1, n, i, mmax-1), ans);
    }
    cout << ans;
}

void solve() {
    if(k == 1)
        sub1();
    if(k == 2)
        sub2();
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}
#define task "MUABANCO"
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}