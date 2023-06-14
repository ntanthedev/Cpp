#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], n, k, cnt = 0;

void solve(){
    sort(a+1, a+1+n);
    
    for(int i = 2; i <= n; i++){
        if(a[i] - a[i-1] > k)
            cnt++;
    }
    cout<<cnt+1;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("PHANNHOM.inp","r",stdin);
    freopen("PHANNHOM.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}