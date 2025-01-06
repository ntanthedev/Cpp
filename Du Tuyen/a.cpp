#include <bits/stdc++.h>
using namespace std;

const int INF = INT32_MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        
        // Initialize adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0; i < m; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        
        // Initialize DP table
        // dp[k][u][v] represents the minimal possible k-th maximum edge on path from u to v with exactly k edges
        // Using 1-based indexing for k
        // To optimize space, we'll use two layers: previous and current
        // Initialize previous layer for k=1
        vector<vector<int>> dp_prev(n + 1, vector<int>(n + 1, INF));
        for(int u =1; u <=n; ++u){
            for(auto &[v, w] : adj[u]){
                dp_prev[u][v] = min(dp_prev[u][v], w);
            }
            dp_prev[u][u] = 0; // Path with 0 edges
        }
        
        // Initialize a 3D DP table
        // Since k can go up to n-1, and n <=400, it's manageable
        // We'll store all k layers
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(n +1, INF)));
        
        // Set k=1
        for(int u=1; u<=n; ++u){
            for(int v=1; v<=n; ++v){
                dp[1][u][v] = dp_prev[u][v];
            }
        }
        
        // Compute DP for k=2 to n-1
        for(int k_len=2; k_len<=n-1; ++k_len){
            // Initialize current layer
            for(int u=1; u<=n; ++u){
                for(int v=1; v<=n; ++v){
                    dp[k_len][u][v] = INF;
                }
            }
            
            // Update current layer based on previous layer
            for(int u=1; u<=n; ++u){
                for(int m=1; m<=n; ++m){
                    if(dp[k_len-1][u][m] == INF) continue;
                    for(auto &[v, w] : adj[m]){
                        // The k-th maximum edge is the maximum between the previous k-1 th and current edge
                        int candidate = max(dp[k_len-1][u][m], w);
                        if(candidate < dp[k_len][u][v]){
                            dp[k_len][u][v] = candidate;
                        }
                    }
                }
            }
        }
        
        // Answer queries
        while(q--){
            int a, b, k_query;
            cin >> a >> b >> k_query;
            if(k_query >=1 && k_query <=n-1){
                int answer = dp[k_query][a][b];
                if(answer != INF){
                    cout << answer << " ";
                }
                else{
                    cout << "-1 ";
                }
            }
            else{
                cout << "-1 ";
            }
        }
        cout << "\n";
    }
    return 0;
}