//created in 2024-08-27-12.49.58 in Code::Blocks 20.03
#include<bits/stdc++.h>

#define h first
#define s second

using namespace std;

const int N = 1e5 + 5;

int n, x;
int dp[N];
pair<int, int> w[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        cin >> w[i].h;
    for(int i = 1; i <= n; i++)
        cin >> w[i].s;

    for(int i = 1; i <= n; i++) {
        for(int j = x; j >= w[i].h; j--) {
            if(j == w[i].h || dp[j - w[i].h] != 0)
                dp[j] = max(dp[j], dp[j - w[i].h] + w[i].s);
        }
    }

    int ans = 0;
    for(int i = 1; i <= x; i++)
        ans = max(ans, dp[i]);
    cout << ans;
}
