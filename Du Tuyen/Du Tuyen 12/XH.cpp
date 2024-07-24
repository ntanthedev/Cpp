#include <bits/stdc++.h>

using namespace std;

#define TASK "xh"
#define MAXN 505
#define INF 1e9

typedef long long ll;

struct rec {
	ll x, y, z, t;
	bool operator < (const rec &o) { return x > o.x || (x == o.x && y > o.y); }
}; 

int n, m;
ll ans, f[MAXN];
vector<rec> a;

int main()
{
	//freopen(TASK".inp", "r", stdin);
	//freopen(TASK".out", "w", stdout);
	scanf("%d %d", &n, &m);
	int b[3];
	for (int i = 1; i <= n; ++i) {
		cin >> b[0] >> b[1] >> b[2];
		sort(b, b + 3);
		a.emplace_back((rec){b[0], b[1], b[2], 1});
		a.emplace_back((rec){b[0], b[2], b[1], 1});
		a.emplace_back((rec){b[1], b[2], b[0], 1});
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[0] >> b[1];
		a.emplace_back((rec){2 * b[0], 2 * b[0], b[1], 2});
	}
	n = a.size();
	sort(a.begin(), a.end());
	f[0] = a[0].z;
	for (int i = 1; i < n; ++i) {
		f[i] = a[i].z;
		for (int j = i - 1; j >= 0; --j) {
			if (a[i].t == 2 || a[j].t == 1) {
				if (a[j].x > a[i].x && a[j].y > a[i].y) f[i] = max(f[i], f[j] + a[i].z);
			} 
			else if (a[j].x * a[j].x > a[i].x * a[i].x + a[i].y * a[i].y)
				f[i] = max(f[i], f[j] + a[i].z);
		}
		ans = max(ans, f[i]);
	}
	cout << ans;
	return 0;
}
