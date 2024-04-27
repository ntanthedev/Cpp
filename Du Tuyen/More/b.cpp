//problem "b"
//created in 09:38:00 - Sat 27/04/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long double x, n;
    cin >> n >> x;

    cout << fixed << setprecision(2) << n / 100 * x;
}