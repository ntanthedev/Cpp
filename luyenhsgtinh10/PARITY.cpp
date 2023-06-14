#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll d = 0, n, x, gmax = 0, dem = 0;
map<ll, ll>M;
void solve(){

}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("PARITY.inp","r",stdin);
    //freopen("PARITY.out","w",stdout);
    cin>>n; M[0] = 1;
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(x%2 == 0)
            d++;
        else
            d--;
        if(M[d] != 0){
            dem += M[d];
        }
        M[d]++;
    }       
    cout<<dem;
    solve();
}