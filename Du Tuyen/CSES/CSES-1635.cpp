//created in 2024-08-27-09.46.53 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;
const int MOD = 1e9 + 7;

int n, s;
int dp[N], w[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> s;
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
        cin >> w[i];

    for(int i = 1; i <= s; i++) {
        for(int j = 1; j <= n; j++) {
            if(i - w[j] >= 0)
                dp[i] += dp[i - w[j]], dp[i] %= MOD;
        }
    }

    cout << dp[s];
}
