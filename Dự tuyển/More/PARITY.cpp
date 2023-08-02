#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll n, x, d = 0, ans = 0;
unordered_map<ll, ll>M;
void solve(){
    M[0] = 1;
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(x%2 == 0) d++;
        else d--;
        //solve
        ans += M[d];
        M[d]++;
    }
    cout<<ans;
}
/*
  1 2  3 4 6
 -1 0 -1 0 1

 4
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("PARITY.inp","r",stdin);
    freopen("PARITY.out","w",stdout);
    cin>>n;
    solve();
}
