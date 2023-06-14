#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n, m, x, a[1000009];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a+1, a+1+n);
    ll res1, res2;
    for(int i = 1; i <= m; i++){
        cin>>x;
        res1 = lower_bound(a+1, a+1+n, x)- a - 1;
        res2 = upper_bound(a+1, a+1+n, x) - a;
        ll ans = min(abs(x-res1), abs(x-res2));
        cout<<ans<<'\n';
    }
}
