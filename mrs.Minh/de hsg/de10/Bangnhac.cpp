#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const long long R = 1e9+7;
const long long N = 1e6+9;
ll s[N], n;
struct S
{
    ll gt, vt;
};
S a[N];
bool cmp(S x, S y){
    return x.gt < y.gt;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bangnhac.inp","r",stdin);
    freopen("bangnhac.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].gt;
        a[i].vt = i;
    }
    sort(a+1, a+1+n, cmp);
    s[0] = 0;
    ll res = 0;
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i].gt;
        cout<<a[i].vt<<" "<<s[i]<<'\n';
        res += s[i];
    }
    cout<<res;
}
