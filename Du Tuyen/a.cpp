#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int u, v, n, m;
vector<int> adj[N];
unordered_map<int, int> idx[N];
int d[N];
bool found = 0;
void dfs(int u, vector<int> res) {
    if(found == 1)
        return;
    d[u] = 1;
    for(auto x: adj[u]) {
        if(d[x] == 0) {
            res.push_back(idx[u][x]);
            dfs(x, res);
            res.pop_back();
        } else {
            cout << "YES\n";
            for(auto g: res)
                cout << g << " ";
            cout << idx[u][x];
            found = 1;
            return;
        }
    }
}
int main() {
    //  name circuit
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen("circuit.inp", "r")) {
        freopen("circuit.inp", "r", stdin);
        freopen("circuit.out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        idx[u][v] = i;
    }
    dfs(1, {});
    if(!found)
        cout << "NO";
}