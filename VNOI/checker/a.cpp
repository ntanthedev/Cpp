#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

pii biases[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

int c(int x) { return x == -1 ? INT_MAX : x; }

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  freopen("MECUNG.INP", "r", stdin);
  freopen("MECUNG.OUT", "w", stdout);
  int m, n, q, x, y, u, v, i, j;
  cin >> m >> n >> x >> y;
  pair<int, pii> mn = {INT_MAX, {}};
  vector<vector<int>> mp(m + 2, vector<int>(n + 2, -1));
  vector<vector<pair<int, pii>>> par(m + 1,
                                     vector<pair<int, pii>>(n + 1, {-1, {}}));
  vector<vector<bool>> visited(m + 1, vector<bool>(n + 1));
  function<void(pii)> bfs = [&](const pii &s) {
    queue<pair<int, int>> q;
    q.push(s);
    par[s.first][s.second].first = 0;
    visited[s.first][s.second] = true;
    while (!q.empty()) {
      auto _u = q.front();
      q.pop();
      for (auto z : biases) {
        int _x = _u.first + z.first, _y = _u.second + z.second;
        if (mp[_x][_y] == 0 && !visited[_x][_y])
          q.push({_x, _y}),
              par[_x][_y] = {par[_u.first][_u.second].first + 1, _u},
              visited[_x][_y] = true;
      }
    }
  };
  for (i = 1; i <= m; i++)
    for (j = 1; j <= n; j++)
      cin >> mp[i][j];
  bfs({x, y});
  for (i = 1; i <= m; i++) {
    if (c(par[i][1].first) < mn.first)
      mn = {par[i][1].first, {i, 1}};
    if (c(par[i][n].first) < mn.first)
      mn = {par[i][n].first, {i, n}};
  }
  for (i = 1; i <= n; i++) {
    if (c(par[1][i].first) < mn.first)
      mn = {par[1][i].first, {1, i}};
    if (c(par[m][i].first) < mn.first)
      mn = {par[m][i].first, {m, i}};
  }
  stack<pii, vector<pii>> res;
  while (mn.second.first > 0) {
    res.push(mn.second);
    mn = par[mn.second.first][mn.second.second];
  }
  cout << res.size() << '\n';
  while (!res.empty())
    cout << res.top().first << ' ' << res.top().second << '\n', res.pop();
  return 0;
}
