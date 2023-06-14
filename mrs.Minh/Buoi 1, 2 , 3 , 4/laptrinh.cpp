#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, x, gmin = LLONG_MAX, vt;
map<ll, ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("laptrinh.inp","r",stdin);
    freopen("laptrinh.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        M[x]++;
    }
    for(auto i:M){
        if(i.first < gmin){
            gmin = i.first;
            vt = i.second;
        }
    }
    cout<<gmin<<'\n'<<vt;
}