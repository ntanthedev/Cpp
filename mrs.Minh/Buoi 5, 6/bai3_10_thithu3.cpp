#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], k, gmax, b[N];
unordered_map<ll, ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai3_10_thithu3.inp","r",stdin);
    freopen("bai3_10_thithu3.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        for(int j = 1; j <= a[i]; j++){
            cin>>k;
            M[k]++;
            gmax = max(gmax, M[k]);
        }
    }
    ll x = 1;
    for(auto i:M){
        if(i.second == gmax)
            b[x++] = i.first;
    }
    sort(b+1,b+1+x);
    for(int i = 1; i <= x; i++)
        if(b[i] != 0)
        cout<<b[i]<<" ";
}

