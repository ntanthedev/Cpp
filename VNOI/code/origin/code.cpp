#include <bits/stdc++.h>

#define ll long long
#define fr(i, d, c) for(ll i = d; i <= c; i++)
#define fl(i, d, c) for(ll i = d; i >= c; i--)
const int N = 2e5 + 9;
using namespace std;

ll n, m, ans;
vector<pair<ll, ll>> adj[N];
tuple<ll, ll, ll> abc;
pair<ll, ll> above[N];
pair<ll, ll> mx[N][3];

void dfs(ll u, ll cha) {
  mx[u][0] = {0, u};
  for(auto [v, w]: adj[u]) if(v != cha) {
    dfs(v, u);
    pair<ll, ll> cur = {mx[v][0].first + w, mx[v][0].second};
    mx[u][2] = max(mx[u][2], cur);
    sort(mx[u], mx[u] + 3, greater<pair<ll, ll>>());
  }
}

void dfs2(ll u, ll cha) {
  for(auto [v, w]: adj[u]) if(v != cha) {
    above[v] = max(above[u], {-w, v});
    if(mx[u][0].second != mx[v][0].second) above[v] = max(above[v], mx[u][0]);
    else if(mx[u][1].second) above[v] = max(above[v], mx[u][1]);
    above[v].first += w;
    dfs2(v, u);
  }

  if(mx[u][1].second && mx[u][1].second != u) {
    if(ans < mx[u][0].first + mx[u][1].first + above[u].first) {
      ans = mx[u][0].first + mx[u][1].first + above[u].first;
      abc = {mx[u][0].second, mx[u][1].second, above[u].second};
    }
  }
  if(mx[u][2].second) {
    if(ans < mx[u][0].first + mx[u][1].first + mx[u][2].first) {
      ans = mx[u][0].first + mx[u][1].first + mx[u][2].first;
      abc = {mx[u][0].second, mx[u][1].second, mx[u][2].second};
    }
  }
  if(above[u].second && above[u].second != u && mx[u][0].second != u) {
    if(ans < mx[u][0].first + above[u].first) {
      ans = mx[u][0].first + above[u].first;
      abc = {mx[u][0].second, u, above[u].second};
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
  cin >> n;
  fr(i, 1, n - 1) {
    ll x, y, w;
    cin>> x >> y >> w;
    adj[x].push_back({y, w});
    adj[y].push_back({x, w});
  }

  above[1] = {0, 1};
  dfs(1, 0);
  dfs2(1, 0);
  cout<<ans * 2<<'\n';
  auto [a, b, c] = abc;
  cout<<a<<" "<<b<<" "<<c<<'\n';
}