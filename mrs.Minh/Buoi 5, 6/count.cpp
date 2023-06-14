#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll m, n, x, cnt = 0;
vector<bool>b(1e9+10, false);
void solve(){
    for(int i = 1; i <= m; i++){
        cin>>x;
        b[x] = true;
    }
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(!b[x])
            cnt++;
    }
    cout<<cnt;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("count.inp","r",stdin);
    //freopen("count.out","w",stdout);
    cin>>m>>n;
    solve();
}