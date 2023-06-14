#include<bits/stdc++.h>
#define tag "Banh"
#define ll long long 
const int N = 1e5+9;
using namespace std;
ll s[N], a[N], n, m, res = 0, ans = 0;
ll sqr(ll x){
    return x*x;
}
void solve(){
    sort(a+1, a+1+n);
    s[0] = 0;
    for(int i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i];
    ll l = n-1;
    while(l > 0){
        if((s[n] - s[l]) - (n-l)*a[l] > m)
            break;
        l--;
    }
    if(l == 0){
        l = 1;
        for(int i = 1; i <= n; i++){
            m -= a[i] - a[l];
            a[i] = a[l];
        }
        if(n >= m){
            for(int i = 1; i <= n; i++){
                if(m > 0){
                    ans += sqr(a[i]-1);
                    m--;
                }
                else
                    ans += sqr(a[i]);
            }
        }
        else{
            ll t = m/n;
            for(int i = 1; i <= n; i++){
                a[i] -= t;
                m -= t;
            }
            for(int i = 1; i <= n; i++){
                if(m > 0){
                    ans += sqr(a[i]-1);
                    m--;
                }
                else
                    ans += sqr(a[i]);
            }
        }
    }
    else{
        for(int i = n; i > l; i--){
            a[i] = a[l];
            m -= a[i] - a[l];
        }
        if(n >= m){
            for(int i = 1; i <= n; i++){
                if(m > 0){
                    ans += sqr(a[i]-1);
                    m--;
                }
                else
                    ans += sqr(a[i]);
            }
        }
        else{
            ll t = m/n;
            for(int i = 1; i <= n; i++){
                a[i] -= t;
                m -= t;
            }
            for(int i = 1; i <= n; i++){
                if(m > 0){
                    ans += sqr(a[i]-1);
                    m--;
                }
                else
                    ans += sqr(a[i]);
            }
        }
    }
    cout<<ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> m >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
}