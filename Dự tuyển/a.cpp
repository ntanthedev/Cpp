#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 23;
int dp[N + 2][3];
int n, a, b;
int dequy(int i, int j) {
    if(dp[i][j] != N + 3) {
        return dp[i][j];
    }
    dp[i][j] = 0;
    int a1 = i;
    int b1 = i;
    if(j == 0) {
        b1--;
    } else {
        a1--;
    }
    while(a1 != b1) {
        if(a1 < b1) {
            a1 += a;
            if(a1 <= n)
                dp[i][j]++;
        } else {
            b1 += b;
            if(b1 <= n)
                dp[i][j]++;
        }
        if(a1 > n && b1 > n) {
            break;
        }
    }
    if(a1 <= n || b1 <= n) {
        dp[i][j] = dp[i][j] + min(dequy(a1, 0), dequy(a1, 1));
    }
    return dp[i][j];
}
int main() {
    cin >> a >> b >> n;
    for(int i = 1; i <= n; i++) {
        dp[i][1] = N + 3;
        dp[i][0] = N + 3;
    }
    int i = a;
    int j = b;
    int res = n;
    if(a <= n)
        res--;
    if(b <= n)
        res--;
    while(i != j) {
        if(i < j) {
            i += a;
            if(i <= n)
                res--;
        } else {
            j += b;
            if(j <= n)
                res--;
        }
        if(i > n && j > n) {
            break;
        }
    }
    if(i > n && j > n) {
        cout << res;
    } else {
        cout << res - min(dequy(i, 1), dequy(i, 0));
    }
    return 0;
}