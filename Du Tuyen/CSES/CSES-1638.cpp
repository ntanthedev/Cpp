//created in 2024-08-27-12.26.22 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 9;
const int MOD = 1e9 + 7;

int n;
int w[N][N], dp[N][N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            if(x == '.')
                w[i][j] = 1;
            else
                w[i][j] = 0;
        }

    dp[0][1] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(w[i][j])
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

    cout << dp[n][n];
}

