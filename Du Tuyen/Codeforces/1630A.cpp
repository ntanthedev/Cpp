//template simple for codeforces by ntannn_
//created in 14:05:15 - Fri 08/03/2024
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, bool> m;
    if(n == 4 && k == 3)
        return cout << -1, void();
    n--;
    if(k == 0) {
        for(int i = 0; i <= n; i++) {
            if(m[i] || m[(i ^ n)])
                continue;
            cout << i << " " << (i ^ n) << '\n';
            m[i] = 1;
            m[(i ^ n)] = 1;
        }
    }
    else if(k != n) {
        m[0] = 1;
        m[k] = 1;
        m[n] = 1;
        m[(k ^ n)] = 1;
        cout << 0 << " " << (k ^ n) << '\n';
        cout << k << " " << n << '\n';
        for(int i = 1; i < n ; i++) {
            if(!m[i] && !m[i ^ n]) {
                cout << i << " " << (i ^ n) << '\n';
                m[i] = 1;
                m[i ^ n] = 1;
            }
        }
    }
    else {
        cout << n << " " << n-1 << '\n';
        cout << n-2 << " " << 1 << '\n';
        m[n] = 1;
        m[n-1] = 1;
        m[n-2] = 1;
        m[1] = 1;
        for(int i = 0; i <= n; i++) {
            if(m[i] || m[(i ^ n)])
                continue;
            cout << i << " " << (i ^ n) << '\n';
        }
    }
    //11111111
    //11111110
    //11111110
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}