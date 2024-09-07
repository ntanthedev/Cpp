// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int n, m, mark[N], sz[N], lab[N];

struct state {
	int l, r;
	bool operator<(const state &other) {
		return l < other.l;
	}

} cor[N];

void sub2() {

	int cnt = 0;

	sort(cor + 1, cor + n + 1);

	for (int i = 1; i <= n; ++i) {
		int last_r = cor[i].r;

		if (mark[i]) continue;
		mark[i] = i;
		++cnt;
		for (int j = i; j <= n; ++j) {
			if (i == j) continue;

			int x = cor[j].l, y = cor[j].r;

			if (x > last_r && x - last_r - 1 <= m && !mark[j]) {
				last_r = y;
				mark[j] = i;
			}
		}


	}

	cout << n - cnt;
}

int Find(int x) {
	return lab[x] == x ? x : lab[x] = Find(lab[x]);
}

bool merge(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a != b) {

		if (sz[a] > sz[b]) swap(a, b);
		lab[b] = a;
		sz[a] += sz[b];
		return 1;
	}

	return 0;
}
void sub3() {

	int cnt = 0;
	sort(cor + 1, cor + n + 1);

	for (int i = 1; i <= n; ++i) {
		sz[i] = 1;
		lab[i] = i;
	}

	multiset<pair<int, int>> pos_l;
	for (int i = 1; i <= n; ++i) {
		pos_l.insert({cor[i].l, i});
	}


	for (int i = 1; i <= n; ++i) {

		mark[i] = i;
		auto it = pos_l.upper_bound({cor[i].r, 1e6});

		if (it == pos_l.end())  {
			++cnt;
		}
		else {

			pair<int, int> v = *it;
			if (v.first <= cor[i].r || v.first - cor[i].r - 1 > m) {

				++cnt;
				continue;
			}
			if (!merge(i, v.second)) cnt++;
			else {
				mark[v.second] = i;
			}

			pos_l.erase(pos_l.find(v));
		}


	}

	cout << n - cnt;
}
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int a, s; cin >> a >> s;
		cor[i].l = a;
		cor[i].r = a + s - 1;
	}

	if (n <= 1e3) sub2();
	else sub3();

}


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// freopen("solver.inp", "r", stdin);
	// freopen("solver.out", "w", stdout);
	freopen("NET.inp", "r", stdin);
	freopen("a.out", "w", stdout);
	solve();
}

