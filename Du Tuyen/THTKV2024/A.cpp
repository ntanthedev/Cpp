//Written by: ntannn_
//created in 09:49:11 - Sat 06/07/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
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

const int N = 5e3 + 10;
const ll MOD = 1e9 + 7;

ll n, m1, m2, ans = 0;
ll D1[N][N], D2[N][N];
vector<vector<int> > adj1, adj2;

void solve() {
    for(int i = 1; i <= n; i++) {
        //bfs1
        queue<int> q1, q2;
        vector<int> trace1(n + 1), trace2(n + 1);
        q1.push(i);
        D1[i][i] = 0;
        D2[i][i] = 0;
        while(!q1.empty()) {
            int u = q1.front(); q1.pop();
            for(auto v : adj1[u]) {
                if(D1[i][v] == -1) { 
                    D1[i][v] = D1[i][u] + 1;
                    q1.push(v);    
                    trace1[v] = u;
                }
            }
        }
        q2.push(i);
        while(!q2.empty()) {
            int u = q2.front(); q2.pop();
            for(auto v : adj2[u]) {
                if(D2[i][v] == -1) { 
                    D2[i][v] = D2[i][u] + 1;
                    q2.push(v);                
                    trace2[v] = u;
                }
            }
        }

        for(int j = i + 1; j <= n; j++) {
            vi t1, t2;
            int v = j;
            while(v != i) {
                t1.push_back(v);
                v = trace1[v];
            }
            t1.pb(i);
            reverse(all(t1));
            v = j;
            while(v != i) {
                t2.pb(v);
                v = trace2[v];
            }
            t2.pb(i);
            reverse(all(t2));
            // dbg(i);
            // dbg(j);
            // dbg(t1);
            // dbg(t2);
            vector<vector<int>> dp(N, vector<int>(N));
            dp[0][0] = 0;
            for(int l = 1; l < t1.size(); l++) 
                for(int r = 1; r < t2.size(); r++) 
                    if(t1[l] == t2[r]) {
                        dp[l][r] = dp[l - 1][r - 1] + 1;
                    }
                    else {
                        dp[l][r] = max(dp[l - 1][r], dp[l][r - 1]);
                    }
            // dbg(dp[t1.size()-1][t2.size()-1]);
            ans += t1.size() - 1 + t2.size() - 1 - dp[t1.size()-1][t2.size()-1];
        }
    }

    // for(int i = 1; i <= n; i++) 
    //     for(int j = i + 1; j <= n; j++) 
    //         cout << "D1 " << i << " " << j << ": " << D1[i][j]<< '\n';

    
    // for(int i = 1; i <= n; i++) 
    //     for(int j = i + 1; j <= n; j++) 
    //         cout << "D2 " << i << " " << j << ": " << D2[i][j]<< '\n';

    cout << ans;
}

void init() {
    read(n);
    adj1.resize(n + 1, vector<int>());
    adj2.resize(n + 1, vector<int>());
    read(m1);
    ll x, y, z;
    memset(D1, 255, sizeof(D1));
    memset(D2, 255, sizeof(D2));
    for(int i = 1; i <= m1; i++) {
        read(x), read(y);
        // D1[x][y] = 1;
        // D1[y][x] = 1;
        adj1[x].push_back(y);
        adj1[y].push_back(x);
    }
    read(m2);
    for(int i = 1; i <= m2; i++) {
        read(x), read(y);
        // D[x][y] = 1,
        // D[y][x] = 1;
        adj2[x].pb(y);
        adj2[y].pb(x);
    }
}

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "a"
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
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}