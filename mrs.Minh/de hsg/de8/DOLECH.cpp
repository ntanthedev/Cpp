#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a[N], dem = 0, n, k;
map<ll, ll>M;

void solve(){   
    for(int i = 1; i <= n; i++){
        if(M[abs(a[i] - k)] > 0)
            dem ++;
            //M[a[i]] = 0;
    }
    cout<<dem/2;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DOLECH.inp","r",stdin);
    freopen("DOLECH.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        M[a[i]]++;
    }
    solve();
}