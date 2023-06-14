#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, k;
struct pt{
    ll vt, gt;
};
pt a[N];

bool cmp(pt x, pt y){
    return x.gt < y.gt || (x.gt == y.gt && x.vt < y.vt);
}
ll dau, dem = 0;
void solve(){
    sort(a+1, a+1+n, cmp);
    dau = a[1].gt;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai3_10_thithu12.inp","r",stdin);
    freopen("Bai3_10_thithu12.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i].gt;
        a[i].vt = i;
    }
    solve();
}