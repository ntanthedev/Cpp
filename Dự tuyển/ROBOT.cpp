#include<bits/stdc++.h>
#define tag "ROBOT"
#define ll long long 
const int N = 2e6+9;
using namespace std;
ll ans, n, a[N], k, x, y;
void solve(){
    cin >> x >> y;
    if(x > y)   
        swap(x, y); //cout<<x<<" "<<y<<"||";
    if(x <= n && n < y && a[x] != a[y]){
        if(a[x] == 1)
            ans--;
        else
            ans++;
    }
    if(a[x] != a[y])
        swap(a[x],a[y]);
    //for(int i = 1; i <= n*2; i++) cout<<a[i]<<" ";
    cout<<ans<<'\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        a[i] = 1;
        a[n+1] = 0;
    }
    ans = n;
    while(k--)
        solve();
}