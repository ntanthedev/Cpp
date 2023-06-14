#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, res, k, ans = 0;
struct pt{
    ll t, p;
};
pt a[N];
bool cmp(pt x, pt y){
    return x.t < y.t || (x.t == y.t && x.p > y.p);
}
void solve(){
    for(int i = 1; i <= n; i++){
        cin>>a[i].t>>a[i].p;
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++){
        if(res >= abs(a[i].t)){
            res += a[i].p;
        }
        else{
            res += k;
            i--;
        }
        ans++;
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>res>>k;
    solve();
}