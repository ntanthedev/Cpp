#include<bits/stdc++.h>
#define tag "NKTICK"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll f[N], a[N], b[N], n;
void solve(){
    f[1] = a[1];
    for(int i = 2; i <= n; i++){
        f[i] = min(f[i-2] + b[i], f[i-1]+a[i]);
    }
    cout<<f[n];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    //memset(f, , sizeof(f));
    for(int i = 1; i <= n;++i)
        f[i] = LLONG_MAX;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 2; i <= n; i++)
        cin >> b[i];
    solve();
}