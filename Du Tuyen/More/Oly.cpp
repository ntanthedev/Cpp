#include<bits/stdc++.h>
#define tag "Oly"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n, k, a[N], b[N], f[5009][5009];
unordered_map<ll, ll>M;
void solve(){
    f[0][0] = 0;
    for(int i = 1; i <= n*k; i++){
        for(int j = 1; j <= n*k; j++){
            if(a[i] == b[j])
                f[i][j] = f[i-1][j-1]+1;
            else
                f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    cout<<f[n*k][n*k];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n*k; i++)
        cin >> a[i];
    for(int i = 1; i <= n*k; i++){
        cin >> b[i];
    }
    solve();
}