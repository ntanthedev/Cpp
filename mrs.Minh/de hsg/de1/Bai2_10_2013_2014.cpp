#include<bits/stdc++.h>
#define ll long long
const ll N = 1e9+7;
using namespace std;
ll n, x, ans = 0;
bool b[N];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("Bai2_10_2013_2014.inp","r",stdin);
    freopen("Bai2_10_2013_2014.out","w",stdout);
    cin>>n;
    memset(b, false, sizeof(b));
    for(int i = 1; i <= n; i++){
        cin>>x;
        b[x] = true;
    }
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(b[x])
            ans++;
    }
    cout<<ans;
}
