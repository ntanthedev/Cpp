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

int n, x, y, a[N], lmax[4*N], lmin[4*N], ans = 0;

void build(int x, int l, int r) {
    if(l == r) {
        lmax[x] = a[l];
        lmin[x] = a[l];
    }
    else {
        int mid = ((l+r)>>1);
        build((x<<1), l, mid);
        build((x<<1)+1, mid+1, r);
        lmax[x] = max(lmax[(x<<1)], lmax[(x<<1)+1]);
        lmin[x] = min(lmin[(x<<1)], lmin[(x<<1)+1]);
    }
}

int query_max(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return INT_MIN;
    if(d <= l && r <= c)
        return lmax[x];
    int mid = ((l+r)>>1);
    return max(query_max(x<<1, l, mid, d, c), query_max((x<<1)+1, mid+1, r, d, c));
}

int query_min(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return INT_MAX;
    if(d <= l && r <= c)
        return lmin[x];
    int mid = ((l+r)>>1);
    return min(query_min(x<<1, l, mid, d, c), query_min((x<<1)+1, mid+1, r, d, c));
}

void solve() {
    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(query_max(1, 1, n, i, j) == x && query_min(1, 1, n, i, j) == y)
                ans++;
        }
    }
    cout << ans;
}

void init() {
    read(n), read(x), read(y);
    for(int i = 1; i <= n; i++)
        read(a[i]);
}
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("MAXMIN.inp","r")) {
        freopen("MAXMIN.inp","r",stdin);
        freopen("MAXMIN.out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}