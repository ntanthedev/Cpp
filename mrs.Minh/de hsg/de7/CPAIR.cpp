#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, x, a[N], dem = 0;
void slove(){
    for(int i = 1; i <= n; i++){
        ll k = upper_bound(a+1, a+1+n, x-a[i])-a-1;
        if(x - k > 0)
            dem += k - i;
    }
    cout<<dem;
}
int main()
{ 
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("CPAIR.inp","r",stdin);
    freopen("CPAIR.out","w",stdout);
    cin>>n>>x;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    slove();
}