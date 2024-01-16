#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 2e3+1;
int a[N][N], dp[N][N], trace[N][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "RACE"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    int n, m;
    cin >> m >> n;
    for(int i = 0; i < m; i++) 
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++) {
        dp[0][i] = a[0][i];
        trace[0][i] = -1;
    }
    for(int i = 1; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(dp[i-1][max(j-1, 0LL)] == min(min(dp[i-1][max(j-1, 0LL)], dp[i-1][j]), dp[i-1][min(j+1, n-1)])) {
                dp[i][j] = dp[i-1][max(j-1, 0LL)]; 
                trace[i][j] = max(j-1, 0LL);
            }
            if(dp[i-1][j] == min(min(dp[i-1][max(j-1, 0LL)], dp[i-1][j]), dp[i-1][min(j+1, n-1)])) {
                dp[i][j] = dp[i-1][j];
                trace[i][j] = j;
            }
            if(dp[i-1][min(j+1, n)] == min(min(dp[i-1][max(j-1, 0LL)], dp[i-1][j]), dp[i-1][min(j+1, n-1)])) {
                dp[i][j] = dp[i-1][min(j+1, n)];
                trace[i][j] = min(j+1, n);
            }
            dp[i][j] += a[i][j];
        }
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans = dp[m-1][i] < dp[m-1][ans] ? i : ans;
    }
    cout << dp[m-1][ans] << '\n';
    vector<int> q;
    q.push_back(a[m-1][ans]);
    int i = m-1;
    while(trace[i][ans] != -1) {
        ans = trace[i--][ans];
        q.push_back(a[i][ans]);
    }
    reverse(all(q));
    for(int j = 0; j < q.size(); j++)
        cout << q[j] << " " ;
}