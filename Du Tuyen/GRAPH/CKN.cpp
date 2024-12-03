//problem "a"
//created in 22:14:58 - Tue 03/12/2024

#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
// #define int int64_t

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

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;

    read(n), read(m);

    vector<vector<int>> adj(n + 1, vector<int>());
    vector<int> num(n + 1, 0), low(n + 1, 0);
    vector<int> cnt(n + 1, 1); 

    for(int i = 1, u, v; i <= m; i++) {
        read(u), read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timeDfs = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        num[u] = low[u] = ++timeDfs;
        // int child = 0;
        
        for(int v : adj[u]) { 
            if(v == p) 
                continue;
            if(!num[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                // ++child;
                if(low[v] >= num[u]) 
                    cnt[u]++;
            }
            else 
                low[u] = min(low[u], num[v]);
        }
    };

    cnt[1] = 0;
    dfs(1, 1);

    for(int i = 1; i <= n; i++) 
        cout << cnt[i] << '\n';

    
}