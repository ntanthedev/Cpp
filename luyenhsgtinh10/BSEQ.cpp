#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, k, sumarr = 0;
ll quytron(ld x){
    ll g = int(x);
    ld f;
    if(g == x)
        return g;
    if(x - g > g+1 - x)
        return g;
    else
        return g+1;
}
void solve(){
    ld arv = sumarr/n;
    arv = quytron(arv);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += abs(a[i] - arv);
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("BSEQ.inp","r",stdin);
    freopen("BSEQ.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sumarr += a[i];
    }
    solve();
}
