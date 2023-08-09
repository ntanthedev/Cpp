#include <bits/stdc++.h>
 
using namespace std;
 
const int maxN = 10010;

int n, m;
bool joint[maxN];
int timeDfs = 0, bridge = 0;
int low[maxN], num[maxN];
vector <int> g[maxN];
vector<int> khop;
vector<pair<int, int>> cau;
 
void dfs(int u, int pre) {
    int child = 0; // Số lượng con trực tiếp của đỉnh u trong cây DFS
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                bridge++;
                cau.push_back(make_pair(v, u));
            }
            child++;
            if (u == pre) { // Nếu u là đỉnh gốc của cây DFS
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}
 
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("cut.inp","r")) {
        freopen("cut.inp","r",stdin);
        freopen("cut.out","w",stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, i);

    int cntJoint = 0;
    for (int i = 1; i <= n; i++) {
        if(joint[i]) {
            cntJoint++;
            khop.push_back(i);
        }
    }

    cout << bridge << ' ' << cntJoint << '\n';
    for(auto i : cau)
        cout << i.first << " " << i.second << '\n';
    for(auto i : khop)
        cout << i << '\n';
} 