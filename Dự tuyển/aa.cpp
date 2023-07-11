#include <bits/stdc++.h>
using namespace std;
long long a[10000099], n, i, s, j, b[100009], u, v, r, L, R, k, h, t[100009], z,
    D[100009];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = i;
    }
    sort(b + 1, b + n + 1);
    j = 1;
    k = 0;
    for(i = n; i >= 1; i--) {
        k++;
        for(j = k - 1; j >= a[i] + 1; j--) {
            D[j + 1] = D[j];
        }
        D[a[i] + 1] = b[i]; 
    }
    for(j = 1; j <= k; j++) {
        cout << D[j] << " ";
    }
}