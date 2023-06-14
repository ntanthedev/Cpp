#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll m, n, a[N], i;


int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai3_10_thithu11.inp","r",stdin);
    freopen("Bai3_10_thithu11.out","w",stdout);
    cin>>n>>m;
    for(i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    i = n;
    ll res = 0, vt;
    while(i >= 1 && a[i] != 1){
        res += a[i]-1;
        i--;
        if(res >= m){
            vt = i;
            break;
        }
    }
    cout<<vt;

}