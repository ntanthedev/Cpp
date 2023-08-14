#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 99;

int n, dp[N];
vector<int> a[N], last;

bool cmp(vector<int> A, vector<int> B) {
    return A.back() < B.back();
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; j++) {
            ll u;
            cin >> u;
            if(a[i].empty())
                a[i].push_back(u);
            else {
                if(a[i].back() < u)
                    a[i].push_back(u);
            }
        }
    }

    sort(a + 1, a + n + 1, cmp);

    last.push_back(0);
    for(int i = 1; i <= n; i++) {
        int sz = a[i].size();
        dp[i] = max(dp[i - 1], sz);
        int dd = 0;
        for(auto u: a[i]) {
            int j = lower_bound(last.begin(), last.end(), u) - last.begin() - 1;
            dp[i] = max(dp[i], dp[j] + sz - dd);
            dd++;
        }
        last.push_back(a[i].back());
    }

    cout << dp[n];
}