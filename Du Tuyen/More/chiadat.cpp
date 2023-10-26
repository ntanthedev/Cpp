#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll n,a[101],total,r = 1e18,dp[1000001];
void solve() {
    dp[0] = 1;
    for(int i = 0; i < n; ++i) {
        for(int j = total-a[i]; j >= 0; --j) {
            dp[j+a[i]] |= dp[j];
        }
    }
    for(int i = 0; i <= total; ++i) {
        if(dp[i]) r = min(r,abs(i-(total-i)));
    }
    cout << r;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("chiadat.inp","r",stdin);
    freopen("chiadat.out","w",stdout);
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        total+=a[i];
    }
    solve();
}