#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
struct pt{
    ll vt, gt;
};
bool cmp(pt x, pt y){
    return((x.gt < y.gt) || (x.gt == y.gt && x.vt < y.vt));
}
pt a[N];
ll n;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai2_10_2015_2016.inp","r",stdin);
    freopen("Bai2_10_2015_2016.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].gt;
        a[i].vt = i;
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++){
        cout<<a[i].vt<<" ";
    }
}