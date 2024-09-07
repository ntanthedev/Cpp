//created in 2024-08-27-09.00.53 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;

int n, s;
int dp[N], w[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> s;

    for(int i = 1; i <= s; i++)
        dp[i] = 1e9;

    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= s; i++) {
        for(int j = 1; j <= n; j++)
            if(i - w[j] >= 0)
                dp[i] = min(dp[i], dp[i - w[j]] + 1);
    }
    cout << (dp[s] != 1e9 ? dp[s] : -1);
}
