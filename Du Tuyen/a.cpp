#include <bits/stdc++.h>
#define nl '\n'
#define V vector
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
using namespace std;

using i64 = long long;

const int A = 6e5 + 5, N = 2e5 + 5;
i64 BIT[A];
int n, q;
V<int> vals;

void update(int p, int v) {
	for (; p < A; p += p & -p)
		BIT[p] += v;
}

i64 query(int p) {
	i64 ans = 0;
	for (; p > 0; p -= p & -p)
		ans += BIT[p];
	return ans;
}

i64 query(int l, int r) {
	return query(r) - query(l - 1);
}

int id(int v) {
	return lower_bound(all(vals), v) - vals.begin() + 1;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> vals.emplace_back();
	}
	tuple<char, int, int> queries[N];
	for (int i = 0; i < q; i++) {
		char type;
		int x, y;
		cin >> type >> x >> y;
		if (type == '?') {
			vals.push_back(x);
			vals.push_back(y);
		}
		queries[i] = {type, x, y};
	}
	sort(all(vals));
	vals.resize(unique(all(vals)) - vals.begin());
	for (int i = 1; i <= n; i++) {
		update(id(vals[i - 1]), 1);
	}
	for (int i = 0; i < q; i++) {
		auto [type, l, r] = queries[i];
		if (type == '!') {
			update(id(vals[l - 1]), -1);
			update(id(r), 1);
			vals[l - 1] = r;
		}
		else {
			cout << query(id(l), id(r)) << nl;
		}
	}
}