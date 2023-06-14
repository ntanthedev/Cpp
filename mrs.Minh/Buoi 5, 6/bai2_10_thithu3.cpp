#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], gmax, scmax = 0;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai2_10_thithu3.inp","r",stdin);
    freopen("bai2_10_thithu3.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        gmax = max(a[i], gmax);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] > scmax && a[i] < gmax)
            scmax = a[i];
    }
    if(scmax == 0){
        cout<<"NO";
        return 0;
    }
    cout<<scmax<<'\n';
    for(int i = 1; i <= n; i++){
        if(a[i] == scmax)
            cout<<i<<" ";
    }
}