//problem "a"
//created in 03:28:12 - Tue 03/12/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "SPIN"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int M, K, n, T;
    cin >> M >> K >> n >> T;
    vector<int> b(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i++) 
        cin >> b[i];

    if(n + K > M) 
        return cout << -1, 0;

    b[0] = 0;
    sort(b.begin(), b.end());

    if(b[0] > K) {
        cout << (K + 1) * K / 2 + K * T;
        return 0;
    }

    int cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        int t = (b[i] - b[i - 1] - 1);
        if(cnt + t <= K) {
            cnt += t;
            sum += (b[i - 1] + b[i]) * t / 2;
        }
        else {
            int tt = K - cnt;
            sum += (b[i - 1] + 1 + b[i - 1] + tt) * tt / 2;
            break;
        }
    }
    cout << sum + K * T;
}