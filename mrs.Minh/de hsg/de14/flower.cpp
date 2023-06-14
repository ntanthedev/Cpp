#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, gmax = 0;
struct pt {
    ll vt, gt;
};
bool cmp(pt x, pt y){
    return x.gt > y.gt;
}
pt a[N];
void solve(){
    for(int i = 1; i <= n; i++){
        cin>>a[i].gt;
        a[i].vt = i;
    }
    sort(a+1, a+1+n,cmp);
    for(int i = 1; i <= n; i++){ 
        cout<<a[i].vt<<" ";
        gmax = max(gmax, a[i].gt + 1);
    }
    cout<<'\n'<<gmax+1;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("flower.inp","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    solve();
}
