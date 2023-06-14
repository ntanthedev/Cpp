#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll gmax = -1, n, x, gmin = N, a[N];
map<ll, ll>M;
void solve(){
    for(int i = 1; i <= n; i++){
        cin>>x;
        M[x]++;
        gmin = min(gmin, M[x]);
        gmax = max(gmax, M[x]);
    }
    cout<<gmin<<" ";
    for(auto i:M){
        if(i.second == gmin)
            cout<<i.first<<" ";
    }
    cout<<'\n'<<gmax<<" ";
    for(auto i:M){
        if(i.second == gmax)
            cout<<i.first<<" ";
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("sach.inp","r",stdin);
    //freopen("sach.out","w",stdout);
    cin>>n;
    solve();
}