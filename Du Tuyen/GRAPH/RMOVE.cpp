//problem "RMOVE"
//created in 08:37:58 - Mon 25/11/2024

#include<bits/stdc++.h>

// #define int int64_t

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "RMOVE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n + 1, vector<int>());
    // vector<vector<int>> h(n + 10, vector<int>(2, 0));
    vector<int> res, path;
    vector<bool> b(n + 1, 0);

    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    if(n == 1) 
        return cout << 0 << '\n' << 1 << '\n' << 1, signed();


    // h[1] = {1, 1};
    
    function<vector<vector<int>>(int, int)> bfs = [&](int be, int en) {
        vector<vector<int>> d(n + 1, vector<int>(2, INT_MAX));
        queue<int> q;

        d[be] = {0, 0};
        q.push(be);

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            if(u == be) {
                for(int v : adj[u]) 
                    d[v][0] = 1;
            }
            else {
                for(int v : adj[u]) {
                    if(d[v][0] == INT_MAX && d[v][1] == INT_MAX)
                        q.push(v);
                    if(d[u][0] != INT_MAX) 
                        d[v][1] = min(d[v][1], d[u][0] + 1);
                    if(d[u][1] != INT_MAX) 
                        d[v][0] = min(d[v][0], d[u][1] + 1);
                }
            }
        }

        return d;
    };

    vector<vector<int>> nguoc = bfs(n, 1);
    vector<vector<int>> xuoi = bfs(1, n);

    dbg(nguoc);
    exit(0);

    int minn = INT_MAX;
    bool flag = 0;

    for(int i = 1; i <= n; i++) {
        if(nguoc[i][0] != INT_MAX && xuoi[i][0] != INT_MAX) {
            if(nguoc[i][0] + xuoi[i][0] - 1 < minn) {
                minn = nguoc[i][0] + xuoi[i][0] - 1;
            }
            flag = 1;
        }
        if(nguoc[i][1] != INT_MAX && xuoi[i][1] != INT_MAX) {
            if(nguoc[i][1] + xuoi[i][1] - 1 < minn) {
                minn = nguoc[i][1] + xuoi[i][1] - 1;
            }
            flag = 1;
        }
    }

    if(!flag)
        cout << -1, signed(); 
    //truy vết

    for(int i = 1; i <= n; i++) {
        if(nguoc[i][0] != INT_MAX && xuoi[i][0] != INT_MAX) {
            if(nguoc[i][0] + xuoi[i][0] - 1 == minn) {
                b[i] = 1;
            }
        }
        if(nguoc[i][1] != INT_MAX && xuoi[i][1] != INT_MAX) {
            if(nguoc[i][1] + xuoi[i][1] - 1 == minn) {
                b[i] = 1;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(b[i]) {
            res.push_back(i);
        }
    }

    cout << minn << '\n';

    function<void(int)> dfs = [&](int u) {
        path.push_back(u);
        for(int v : adj[u]) {
            if(b[v]) {
                dfs(v);
                break;
            }
        }
    };

    dfs(1);

    for(int i = 0; i <= minn; i++) 
        cout << path[i] << " ";
    cout << '\n';
    for(int i = minn; i < path.size(); i++) 
        cout << path[i] << " ";
}