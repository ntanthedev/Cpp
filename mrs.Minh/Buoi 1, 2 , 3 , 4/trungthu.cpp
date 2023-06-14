#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, gmin = LLONG_MAX, a[1000009], res = 0, m, dem = 0;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        gmin = min(gmin, a[i]);
        res += a[i];
        dem++;
    }
    while(res+gmin <= m){
        res += gmin;
        dem++;
    }
    cout<<dem<<'\n';    
}