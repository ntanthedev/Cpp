#include <bits/stdc++.h>
using namespace std;
long long i, n, nz, z[1123456], a[1123456], m, q, k, ans;
void QL1(int i, int q) {
    if(i > k) {
        z[nz++] = q;
        return;
    }
    QL1(i + 1, q);
    if(q + a[i] <= m) {
        QL1(i + 1, q + a[i]);
    }
}
void QL2(int i, int q) {
    if(i > n) {
        ans += upper_bound(z, z + nz, m - q) - lower_bound(z, z + nz, m - q);
        return;
    }
    QL2(i + 1, q);
    if(q + a[i] <= m)
        QL2(i + 1, q + a[i]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FAIR.inp", "r", stdin);
    freopen("FAIR.out", "w", stdout);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> a[i];
    k = n / 2;
    nz = 0;
    QL1(1, 0);
    sort(z, z + nz);
    ans = 0;
    QL2(k + 1, 0);
    cout << ans;
}
