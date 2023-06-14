#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pu push_back
#define po pop_back 
const long long MOD = 1e9+7;
const long long N = 1e3+9;
ll m, n, a[N][N], h[N], ans = 0, L[N];
vector<int>vt;
void input(){
    memset(h, 0, sizeof(h));
    cin>>m>>n; L[n+1] = n+1;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin>>a[i][j];
            if(a[i][j] == '0'){
                ans++;
                h[j]++;
                L[j] = L[j+1];
            }
            else{
                h[j] = 0;
                L[j] = i;
            }
        }
        solve();
    }
}
void solve(){
    for(int i = 1; i <= n; i++){
        ll t = min(h[i], L[i]);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    input();
    solve();
}