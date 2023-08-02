#include<bits/stdc++.h>
#define ll long long
#define xau "MARRAY"
const int N = 1e6+9;
using namespace std;
ll x, n, gmax = LLONG_MIN;
void solve(){
    for(int i = 1; i <= n; i++){
        cin >> x;
        gmax = max(gmax, x);
        cout<<gmax<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n;
    solve();
}
