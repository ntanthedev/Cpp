#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, T, a[N], lmax[4*N], lmin[4*N];

void build(int id, int l, int r) {
    if(l == r) {
        lmax[id] = a[l];
        lmin[id] = a[r];
    }
    else {
        int mid = (l+r)>>1;
        build(id<<1, l, mid);
        build((id<<1)+1, mid+1, r);
        lmax[id] = max(lmax[id<<1], lmax[(id<<1)+1]);
        lmin[id] = min(lmin[id<<1], lmin[(id<<1)+1]);
    }
}

ll get_max(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return INT_MIN;
    if(d <= l && r <= c)
        return lmax[x];
    int mid = (l+r)>>1;
    return max(get_max(x<<1, l, mid, d, c),get_max((x<<1)+1, mid+1, r, d, c));
}

ll get_min(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return INT_MAX;
    if(d <= l && r <= c)
        return lmin[x];
    int mid = (l+r)>>1;
    return min(get_min(x<<1, l, mid, d, c),get_min((x<<1)+1, mid+1, r, d, c));
}

bool check(int k) {
    int l = 1, r = k;
    while(r <= n) {
        ll mmax = get_max(1, 1, n, l, r);
        ll mmin = get_min(1, 1, n, l, r);
        if(mmax - mmin <= T)
            return true;
        l++, r++;
    }
    return false;
}

void solve() {
    build(1, 1, n);
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(check(mid)) {
            l = mid+1;
            ans = max(ans, mid);
        }
        else {
            r = mid-1;
        }
    }
    cout << ans ;
}

void init() {
    read(n), read(T);
    for(int i = 1; i <= n; i++) 
        read(a[i]);
}

#define task "game"
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