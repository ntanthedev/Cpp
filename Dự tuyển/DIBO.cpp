#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll ans, n, m;
void solve(){
    if(n <= m)
        ans = -1;
    else{
        ans = n/m;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DIBO.inp","r",stdin);
    freopen("DIBO.out","w",stdout);
    cin >> n >> m;
    solve();
}
