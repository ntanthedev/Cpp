//Writed by Jethro_
//------------------------
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], lef[N], righ[N],  ans = 1e9, t;
map<int, int> T, P;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        lef[i] = T[a[i] - 1] + 1;
		T[a[i]] = lef[i];
    }
    for (int i = n; i >= 1; --i) {
        righ[i] = P[a[i] - 1] + 1;
		P[a[i]] = righ[i];
    }
    for (int i = 1; i <= n; ++i) {
		int v = i - lef[i] + n - i + 1 - righ[i], t = v + (max(lef[i], righ[i]) - min(lef[i], righ[i]));
		if (righ[i] == 1 || lef[i] == 1) continue;
		ans = min(ans, t);

	}

    cout << (ans == 1e9 ? -1 : ans) << '\n';
    T.clear();
    P.clear();
    for (int i = 1; i <= n; ++i) righ[i] = lef[i] = 0;
    ans = 1e9;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> t;
    while(t--) solve();

}