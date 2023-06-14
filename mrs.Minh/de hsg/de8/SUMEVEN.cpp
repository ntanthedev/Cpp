#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll l , r, a[N], q, s[N], n;

void solve(){
    for(int i = 1; i <= q; i++){
        cin>>l>>r;
            cout<<s[r] - s[l-1];
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("SUMEVEN.inp","r",stdin);
    freopen("SUMEVEN.out","w",stdout);
    cin>>n>>q; s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1];
        if(i%2 == 0)
            s[i] += a[i];
    }
    solve();
}