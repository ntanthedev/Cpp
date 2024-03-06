#include <bits/stdc++.h>

using namespace std;

vector <int> a;
bool p[500];

bool isInteresting(int x) {
    int res = 0;
    while (x > 0) {
        res += (x % 10) * (x % 10);
        x /= 10;
    }
    return p[res];
}

void init() {
    for (int i = 2; i < 500; i++) {
        p[i] = true;
        for (int j = 2; j <= i / 2; j++)
            if (i % j == 0)
                p[i] = false;
    }

    for (int i = 1; i <= 1e6 + 1; i++)
        if (isInteresting(i)) 
            a.push_back(i);
}

void solve() {
    int n;
    cin >> n;
    cout << (*upper_bound(a.begin(), a.end(), n)) << '\n';
}
 
signed main() {
    // freopen("a.inp", "r", stdin); freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    
    int test;
    cin >> test;
    while (test--)
        solve();
    
}
