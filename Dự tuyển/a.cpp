#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

ll ans = 0, n, a[N], x, dp[N];

void solve() {
    cin >> n;
    fo(i, 1, n) 
        cin >> a[i];
    cin >> x;
    fo(i, 1, n)
        a[i] -= x;
    bool flag = 0;
    fo(i, 1, n) {
        if(!flag || dp[i-1] + a[i] >= 0) {
            ans++;
            dp[i] = min(dp[i-1] + a[i], a[i]);
            flag = 1;
        }
        else {
            flag = 0;
            dp[i] = 0;
        }
    }
    cout << ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("pink2.inp","r")){
        freopen("pink2.inp","r",stdin);
        freopen("pink2.out","w",stdout);
    }
    int test_case;
    cin >> test_case;
    while(test_case--)
        solve();
}