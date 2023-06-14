#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
unordered_map<ll, bool>M;
ll m, n, dem = 0, x;
void solve(){

}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("SSORT1.inp","r",stdin);
    freopen("SSORT1.out","w",stdout);
    cin>>m>>n;
    for(int i = 1; i <= m; i++){
        cin>>x;
        M[x] = true;
    }
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(M[x])
            dem++;
    }
    cout<<dem;
    //solve();
}
