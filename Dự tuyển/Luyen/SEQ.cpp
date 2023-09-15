#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define left (id<<1)
#define right (id<<1)+1
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, Q, b[N], a[N], lsum[N], leaf[N];

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

void build(int id, int l, int r) {
    if(l == r) {
        lsum[id] = a[l] + b[l];
        leaf[l] = id;
    }
    else {
        int mid = (l+r)>>1;
        build(left, l, mid);
        build(right, mid+1, r);
        lsum[id] = lsum[left] + lsum[right];
    }
}

void update(int v, ll w) {
    ll d = (w+b[v]) - (a[v]+b[v]);
    int id = leaf[v];
    for(; id > 0; id /= 2) {
        lsum[id] += d;
    }
    a[v] = w;
}

ll get_sum(int id, int l, int r, int u, int v) {
    if(l > v || r < u)
        return 0;
    if(u <= l && r <= v)
        return lsum[id];
    int mid = (l+r)>>1;
    return get_sum(left, l, mid, u, v) + get_sum(right, mid+1, r, u, v);
}

void sub3() {
    build(1, 1, n);
    while(Q--) {
        int c, l, r;
        read(c), read(l), read(r);
        if(c == 1) 
            update(l, r);
        else 
            cout << get_sum(1, 1, n, l, r) << '\n';
    }
}

void sub1() {
    while(Q--) {
        ll c, l, r;
        read(c), read(l), read(r);
        if(c == 2) {
            ll res = 0;
            for(int i = l; i <= r; i++) {
                res += a[i] + b[i];
            }
            cout << res << '\n';
        }
        else {
            a[l] = r;
        }
    }
}

void solve() {
    if(n <= 1e3 && Q <= 1e3)    
        sub1();
    else 
        sub3();
}

void init() {
    read(n), read(Q);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
    }
    for(int i = 1; i <= n; i++) {
        ll j = i;
        while(j%2 == 0)
            j /= 2;
        b[i] = j;
    }
}   

#define task "SEQ"
signed main() {
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