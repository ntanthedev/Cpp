#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
int n, k, ans, f[50005][505];
vector<int> graph[1000002];
void dfs(int u, int cha) {
    f[u][0] = 1;
    for(int v: graph[u]) {
        if(v == cha)
            continue;
        dfs(v, u);
        for(int j = 0; j < k; j++)
            ans += f[u][j] * f[v][k - j - 1];
        for(int j = 1; j <= k; j++)
            f[u][j] += f[v][j - 1];
    }
}
main() {
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    cout << ans;
}