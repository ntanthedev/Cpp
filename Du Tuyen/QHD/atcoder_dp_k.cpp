// problem "atcoder_dp_k"
// created in 14:23:13 - Sat 18/05/2024

#include <bits/stdc++.h>

#define int int64_t
const int N = 1e5 + 5;

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> dp(k + 1);

    for(auto& i: a)
        cin >> i;

    for(int i = 1; i <= k; i++)
        if(i < a.front())
            dp[i] = 0;
        else
            for(auto j: a)
                if(i >= j && !dp[i - j])
                    dp[i] = 1;

    cout << (dp[k] ? "First" : "Second");
}