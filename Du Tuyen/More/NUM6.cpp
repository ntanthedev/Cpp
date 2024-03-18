#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

long long n, a[N], mx;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[n - 1] * a[n - 2] > a[1] * a[2]) {
        mx = a[n] * a[n - 1] * a[n - 2] + max(a[1] * a[2], a[n - 4] * a[n - 5]) * a[n - 3];
    }else {
        mx = max(mx, a[1] * a[2] * a[n] + max(a[3] * a[4], a[n - 3] * a[n - 2]) * a[n - 1]);
    }
    cout << mx;
    


}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("NUM6.inp", "r", stdin);
    freopen("NUM6.out", "w", stdout);
    solve();

}


/*

    max(am * am, duong * duong) * maxx + 
*/