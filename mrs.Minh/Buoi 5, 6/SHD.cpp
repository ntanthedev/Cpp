#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], gmax = 0, res = 0, vt;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("SHD.inp","r",stdin);
    freopen("SHD.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] >= gmax){
            gmax = a[i];
            vt = i;
        }
        res += a[i];
    }
    res -= gmax;
    if(gmax - res > 0){
        cout<<vt<<" "<<gmax;
    }
    else
    cout<<-1;
}