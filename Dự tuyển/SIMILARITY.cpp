#include<bits/stdc++.h>
#define ll long long
const int N = 1e3+9;
using namespace std;
ll dp[N][N], m, n, a[N], b[N];
void solve(){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("SIMILARITY.inp","r",stdin);
    //freopen("SIMILARITY.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    solve();
}
