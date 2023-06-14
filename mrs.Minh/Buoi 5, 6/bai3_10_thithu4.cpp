#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], k;
map<ll , ll >M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai3_10_thithu4.inp","r",stdin);
    freopen("bai3_10_thithu4.out","w",stdout);
    cin>>n>>k;
    ll d = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(M[a[i]])
            d += M[a[i]];
        M[a[i] - k]++;
        M[a[i] + k]++;
    }
    cout<<d;
}