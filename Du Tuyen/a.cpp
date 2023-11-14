#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll poww(int x) {
	ll res = 1;
	for (int i = 1; i <= x; i++) { res *= 10; }
	return res;
}

int main() {
	int Q;
	ll k;
	cin >> Q;

	while(Q--) {
		cin >> k;
		int n = 1;
		while (k > n * 9 * poww(n - 1)) {
			k -= n * 9 * poww(n - 1);
			n++;
		}
		ll num = (k - 1) / n + poww(n - 1);
		int anss = (int)((k - 1) % n)
		cout << to_string(num)[anss] << '\n';
	}
}