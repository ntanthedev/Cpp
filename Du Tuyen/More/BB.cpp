//Written by: ntannn_
//created in 14:15:33 - Sun 17/03/2024
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

const int N = 5e3 + 10;
const ll MOD = 1e9 + 7;

ll n, t, a[N], need[N];
map<ll, int> M;

void solve() {
    // memset(M, 0, sizeof(M));
    for(int i = 1; i <= n; i++) {
        need[i] = (i < t ? a[t] - a[i] : 0);   
        // cout << need[i] << " ";
    }
    ll ans = 0;
    for(int i = 3; i < t; i++) {
        for(int j = 1; j < i - 1; j++) {
            M[a[j] + a[i-1]]++;    
        }
        ans += M[need[i]];
    }
    cout << ans;
}

void init() {
    cin >> n >> t;
    for(int i = 1; i <= n; i++) { 
        cin >> a[i];
    }
}

#define task "BB"
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