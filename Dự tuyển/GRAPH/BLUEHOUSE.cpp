#include <bits/stdc++.h>
 
#define nl '\n'
 
using namespace std;
 
using i64 = long long;
 
signed main() {
  cin.tie(0), ios::sync_with_stdio(0);
#define TASK "BLUEHOUSE"
  if (fopen(TASK ".inp", "r")) {
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
  }
 
  int n;
  cin >> n;
  int m = n - 1;
  vector<vector<pair<int, int>>> adj(n);
 
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].emplace_back(v, i);
    adj[v].emplace_back(u, i);
  }
 
  vector<int> num(n, 0), low(n, 0);
  int ti = 0;
 
  vector<int> is_bridge(m, 0);
 
  function<void(int, int)> dfs = [&](int u, int pid) -> void {
    num[u] = low[u] = ++ti;
    for (auto [v, id] : adj[u]) {
      if (id == pid) continue;
      if (num[v]) {
        low[u] = min(low[u], num[v]);
      } else {
        dfs(v, id);
        low[u] = min(low[u], low[v]);
        if (low[v] > num[u]) {
          is_bridge[id] = 1;
        }
      }
    }
  };
 
  dfs(0, -1);
 
  vector<int> belong(n, -1);
  vector<vector<int>> comps;
  for (int i = 0; i < n; i++) {
    if (belong[i] == -1) {
      int c = comps.size();
      comps.emplace_back();
      queue<int> q;
      q.push(i);
      belong[i] = c;
      while (q.size()) {
        int u = q.front();
        q.pop();
        comps.back().push_back(u);
 
        for (auto [v, id] : adj[u]) {
          if (is_bridge[id]) continue;
          if (belong[v] != -1) continue;
          belong[v] = c;
          q.push(v);
        }
      }
    }
  }
  int sz = comps.size();
  vector<vector<int>> nadj(sz);
 
  for (auto& comp : comps) {
    for (int u : comp) {
      for (auto [v, id] : adj[u]) {
        if (belong[u] == belong[v]) continue;
        nadj[belong[u]].push_back(belong[v]);
      }
    }
  }
 
  for (int i = 0; i < sz; i++) {
    sort(nadj[i].begin(), nadj[i].end());
    nadj[i].erase(unique(nadj[i].begin(), nadj[i].end()), nadj[i].end());
  }
 
  // now the graph is a tree
  num.assign(sz, 0);
  ti = 0;
 
  vector<int> leaves;
 
  vector<pair<int, int>> ans;
 
  function<void(int, int)> dfs2 = [&](int u, int p) {
    if (nadj[u].size() == 1) {
      // this is a leaf
      leaves.push_back(u);
      if (leaves.size() >= 3) {
        int a = leaves[0], b = leaves[1], c = leaves[2];
        ans.emplace_back(comps[a][0], comps[c][0]);
        leaves.pop_back();
        leaves.pop_back();
        leaves.back() = b;
      }
    }
    for (int v : nadj[u]) {
      if (v == p) continue;
      dfs2(v, u);
    }
  };
 
  dfs2(0, 0);
 
  if (leaves.size() == 2) {
    ans.emplace_back(comps[leaves[0]][0], comps[leaves[1]][0]);
  } else if (leaves.size() == 1) {
    ans.emplace_back(comps[leaves[0]][0], comps[0][0]);
  }
 
  cout << ans.size() << nl;
  for (auto [u, v] : ans) cout << ++u << " " << ++v << nl;
}