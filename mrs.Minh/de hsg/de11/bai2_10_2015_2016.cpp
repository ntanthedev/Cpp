#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n;
struct pt{
    ll vt, gt;
};
pt a[N];
bool cmp(pt x, pt y){
    return (x.gt < y.gt || (x.gt == y.gt && x.vt < y.vt));
}
void solve(){
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++)
        cout<<a[i].vt<<" ";
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai2_10_2015_2016.inp","r",stdin);
    freopen("bai2_10_2015_2016.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].gt;
        a[i].vt = i;
    }
    solve();
}