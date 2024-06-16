#include<bits/stdc++.h>

using namespace std;

const int N = 100000 + 5;

int n, m = 0, root = 1;
int h[N], st[N], en[N], tour[N];
vector<int> adj[N];

// Trong các giá trị bên trên:
// h[u] là khoảng cách từ đỉnh gốc đến đỉnh u.
// st[u] là vị trí đầu tiên của đỉnh u trong mảng tour.
// en[u] là vị trí cuối cùng của đỉnh u trong mảng tour.

void input() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void add(int u) {
    tour[++m] = u;
    en[u] = m;
}

void dfs(int u, int parent_of_u) {
    h[u] = h[parent_of_u] + 1;
    add(u);
    st[u] = m;
    for (int v : adj[u]) {
        if (v != parent_of_u) {
            dfs(v, u);
        }
    }
    if (u != root) add(parent_of_u);
}

int main() {
    input();
    dfs(root, 0);

    for(int i = 1; i <= m; i++) 
        cout << tour[i] << " ";
    return 0;
}