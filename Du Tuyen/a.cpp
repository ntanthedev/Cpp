//problem "a"
//created in 21:43:17 - Thu 29/08/2024

#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int n;
vector<int> adj[N];
//adj[u] : là vector chứa danh sách các nhân viên trực tiếp của u 
int f[N];
//f[i] là số nhân viên của i

int lz[N];

void dfs(int u) {
    if(lz[u]) 
        f[u] += lz[u];
    
    for(int v : adj[u]) {
        lz[v] += lz[u];
        //code e 
    }
    lz[u] = 0;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        adj[u].push_back(v);
    }

    dfs(1);

    for(int i = 1; i <= n; i++) 
        cout << f[i] << " " ;
}

/*
u -> v
*/