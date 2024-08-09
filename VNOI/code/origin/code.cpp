#include <bits/stdc++.h>
using namespace std;

const int N = 1505;
const int mod = 1e9 + 7;
int n, m, a[20], l[N], d[N];
long long f[20][2][N];

bool check(int x) {
	if (x == 1) {
		return true;
	}
	l[x] = 1;
	int s = 0;
	while (x != 0) {
		s += (x % 10) * (x % 10);
		x /= 10;
	}
	if (!l[s]) {
		return check(s);
	}
	return false;
}

long long cal(int i, int ok, int s) {
	if (i > n) {
		return 1 - d[s];
	} 
	if (f[i][ok][s] + 1) {
		return f[i][ok][s];
	}
	int w = (ok != 0 ? 9 : a[i]);
	f[i][ok][s] = 0;
	for (int j = 0; j <= w; j++) {
		f[i][ok][s] += cal(i + 1, ok | (j < a[i]), s + j * j);
	}
	return f[i][ok][s];
}

long long precal(long long x) {
	n = 0;
	memset(f, 255, sizeof(f));
	while (x != 0) {
		a[++n] = x % 10;
		x /= 10;
	}
	reverse(a + 1, a + n + 1);
	return cal(1, 0, 0);
}

void solve() {
	long long ll, rr;
	cin >> ll >> rr;
	cout << precal(rr) - precal(ll - 1) << "\n";
}

int main() {
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
	int test; 
	cin >> test;
	for (int i = 1; i <= 1500; i++) {
		for (int j = 1; j <= 1500; j++) {
			l[j] = 0;
		}
		d[i] = check(i);
	}
	while (test--) {
		solve();
	}
}
