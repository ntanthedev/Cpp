//template simple for codeforces by ntannn_
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve() {
	int n, m, ans;
	cin >> n >> m;
	vector<int> par(n + 1);
	for(int i = 1; i <= n; i++) 
		par[i] = i;

	function<int(int)> find_par = [&](int x) {
		return x == par[x] ? x : par[x] = find_par(par[x]);
	};

	ans = 0;
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		if(u == v)
			continue;
		if(find_par(v) == find_par(u))
			ans++;
		else
			par[u] = v;
		ans++;
	}
	cout << ans << '\n';
}

int32_t main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int test_case;
	for(cin >> test_case;test_case--;cout << '\n') 
		solve();
}