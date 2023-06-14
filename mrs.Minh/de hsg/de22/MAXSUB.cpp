#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll gmax = 0, m, n, a[N], x[N];
void solve(){
    ll res = 0;
    for(int i = 1; i <= n; i++)
        res += a[i]*x[i];
    gmax = max(gmax, res%m);
}
void tim(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n)
            solve();
        else
            tim(i+1);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("MAXSUB.inp","r",stdin);
    freopen("MAXSUB.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    tim(1);
    cout<<gmax;
}