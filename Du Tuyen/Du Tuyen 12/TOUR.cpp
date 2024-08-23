#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e3 + 3;

int n, m;
vector<pair<int, int>> adj[N];
bool b[N];
bool ok = 0;
vector<pair<int, int>> res;
double ans = INT_MAX;

void dfs(int u) {
    // cout << u << " ";
    for(pair<int, int> e : adj[u]) {
        int v = e.first, w = e.second;
        if(b[v]) {
            int sum = w, cnt_edge = 1;
            for(vector<pair<int, int>>::reverse_iterator it = res.rbegin(); it != res.rend(); it++) {
                if(it->first != v) {
                    cnt_edge++;
                    sum += it->second;
                    // cout << "check res: " << it->first << " " << it->second << '\n'; 
                }
                else 
                    break;
            }
            // cout << "check: " << v << " " << sum << " " << cnt_edge << " " << (double)sum / cnt_edge << '\n';
            ans = min(ans, (double)sum / cnt_edge);
        }
        else {
            b[v] = 1;
            res.push_back({v, w});
            dfs(v);
            res.pop_back();
        }
    } 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "TOUR"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n >> m;

    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    for(int i = 1; i <= n; i++) {
        if(!b[i]) {
            res.push_back({i, 0});
            b[i] = 1;
            dfs(i);
        }
    }

    if(ans == 0.00)
        cout << "NO TOUR";
    else    
        cout << fixed << setprecision(2) << ans;
}