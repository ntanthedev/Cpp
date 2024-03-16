//Written by: ntannn_
//created in 18:09:10 - Fri 15/03/2024
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

template<typename T> inline void read(T& x) {
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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

int n, m;
ll a[N], b[N], S = 0, E = 0, Q = 0;
map<ll, ll> A, B;
vector<pll> ca, cb;

void solve() {
    ll temp = 0;
    for(auto i : A) {
        ca.eb(i.fi, i.se + temp);
        temp += i.se;
    }
    temp = 0;
    for(auto i : B) {
        cb.eb(i.fi, i.se + temp);
        temp += i.se;
    }
    for(auto i : B) {
        auto it = lower_bound(all(ca), mp(i.fi, 0LL));
        if(it == ca.begin())
            continue;
        it--;
        S += i.se * it->se;
    }
    for(auto i : A) {
        if(B[i.fi] != 0)
            E += i.se * B[i.fi];
    }
    for(auto i : A) {
        auto it = lower_bound(all(cb), mp(i.fi, 0LL));
        if(it == cb.begin())
            continue;
        it--;
        Q += i.se * it->se;
    }
    cout << S << " " << E << " " << Q;
}

void init() {
    read(m), read(n);
    for(int i = 1; i <= m; i++) { 
        read(a[i]);
        a[i] += a[i-1];
        for(int j = i; j >= 1; j--) {
            ll s = a[i] - a[j-1];
            A[s]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += b[i-1];
        for(int j = i; j >= 1; j--) {
            ll s = b[i] - b[j-1];
            B[s]++;
        }
    }
}

#define task "SEQ2SC"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}