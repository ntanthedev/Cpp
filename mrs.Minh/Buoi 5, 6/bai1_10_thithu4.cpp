#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, r, a[N], k, d = 0;
unordered_map<ll, bool>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai1_10_thithu4.inp","r",stdin);
    freopen("bai1_10_thithu4.out","w",stdout);
    cin>>n>>k;
    M[0] = 1; 
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        r = a[i]%k;
        if(M[r] == 0)
            d++;
        M[r] = 1;
    }
    cout<<d;
}