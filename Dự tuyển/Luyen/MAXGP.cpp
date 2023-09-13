#include<bits/stdc++.h>


const int N = 1e5+9;
const int MOD = 1e9+7;
using namespace std;

typedef long long ll;

ll n, q, a[N];
vector<int> dp, ans;
void sub3() {
    dp.resize(n+1, 1);
    ans.resize(n+2);
    for(int i = 1; i < n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(a[j]/a[i] == q) {
                dp[j] = dp[i] + 1;
                ans[dp[j]]++;    
            }
        }
    }
    for(int i = n-1; i >= 1; i--)
        ans[i] = (ans[i]%MOD + ans[i+1]%MOD)%MOD; 
    for(int i = 2; i <= n; i++)
        cout << ans[i] << " " ;
}

void solve() {
    sub3();
}

#define task "MAXGP"
signed main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
}