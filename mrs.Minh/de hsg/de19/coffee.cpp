#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, res = 0;
struct pt {
    ll h, m;
};
pt a[N];
bool cmp(pt x, pt y){
    return x.h < y.h || (x.h == y.h && x.m < y.m);
}
void solve(){
    sort(a+1, a+1+n, cmp);
    ll temp = 1;
    for(int i = 2; i <= n; i++){
        if(a[i].h == a[i-1].h && a[i].m - a[i-1].m <= 1){
            temp++;
        }
        else
            temp = 1;
        res = max(res, temp);
    }
    cout<<res;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("coffee.inp","r",stdin);
    freopen("coffee.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i].h>>a[i].m;
    solve();
}