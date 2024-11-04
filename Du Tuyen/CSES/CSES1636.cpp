//created in 2024-08-27-10.10.04 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;
const int MOD = 1e9 + 7;

int n, s;
int dp[N], w[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> s;

    for(int i = 1; i <= n; i++)
        cin >> w[i];

    dp[0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = w[i]; j <= s; j++) {
            dp[j] += dp[j - w[i]];
            dp[j] %= MOD;
        }
    cout << dp[s];
}

