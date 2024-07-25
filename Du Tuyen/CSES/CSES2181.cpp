#include <bits/stdc++.h>
using namespace std;
 
const int N = 1025;
const int mod = 1e9 + 7;
int n, m, dp[N][N];
vector < int > s[N];
 
bool check(int x, int y) {
	for (int i = 0; i < n; i++) {
		if (x >> i & 1) {
			if (y >> i & 1) {
				return false;
			}
		}
		else {
			if (y >> i & 1) {
				continue;
			}
			else {
				if (i + 1 < n && !(x >> (i + 1) & 1) && !(y >> (i + 1) & 1)) {
					i++;
					continue;
				}
				return false;
			}
		}
	}
	return true;
}
 
void solve() {
	cin >> n >> m;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << n); j++) {
			if (check(i, j)) {
				s[i].push_back(j);
			}
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < (1 << n); j++) {
			for (int k : s[j]) {
				dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
			}
		}
	}
	cout << dp[m][0];
}
 
int main() {
	int test = 1;
	while (test--) {
		solve();
	}
}