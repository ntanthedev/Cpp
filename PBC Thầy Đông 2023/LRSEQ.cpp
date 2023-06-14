#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

using namespace std;

template<typename T>
inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;
const long long  INF=1e18;
bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}
//----------------------------
ll n, ans = LLONG_MIN, a[N], L, R, pre[N], lmin[N];

//----------------------------

void sub2() {
    for(int s = L; s <= R; s++) {
        for(int i = 0; i <= n - s - 1; i++) {
            ans = max(ans, pre[i + s] - pre[i]);
        }
    }
    cout << ans;
}
void build(int x, int l, int r) {
    if(l == r)
        lmin[x] = pre[l];
    else {
        int mid = (l + r) / 2;
        build(x * 2, l, mid);
        build(x * 2 + 1, mid + 1, r);
        lmin[x] = min(lmin[x * 2], lmin[x * 2 + 1]);
    }
}
long long  query(int x, int l, int r, int i, int j) {
    if(l > j || r < i)
        return INF;
    if(i <= l && r <= j)
        return lmin[x];
    int mid = (l + r) / 2;
    return min(query(x * 2, l, mid, i, j), query(x * 2 + 1, mid + 1, r, i, j));
}
void sub3() {
    build(1, 0, n);
    // for(int i = 1; i <= n; i++)
    //     cout << pre[i] << " "; cout << '\n';
    ans=-INF;
    for(ll i = L; i <= n; i++) {
        ans = max(ans, pre[i] - query(1, 0, n, max(i-R,0LL), i - L));
        // cout << "#" << i << ": " << i - (R - L + 1) - 1 << " " << i - 1 << "
        // " << pre[i] - query(1, 0, n, i - (R - L + 1), i - 1) << '\n';
    }
    cout << ans;
}
void init() {
    read(n), read(L), read(R);
    pre[0] = 0;
    for(int i = 1; i <= n; i++) {
        read(a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
        sub3();
}
//-----TASK----------
#define task ""
//-------------------
int32_t main() {
    //---------------------------------
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    //---------------------------------
    init();
    // solve();
}