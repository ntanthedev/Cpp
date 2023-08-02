#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll x[N], n;
void solve(){
    for(int i = 1; i <= n; i++){
        ll ans = 0;
        for(int j = 1; j <= n; j++){
            if(x[j] > i)
                ans++;
            if(x[j] == i)
                break;
        }
        cout<<ans<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("INVERSION.inp","r",stdin);
    //freopen("INVERSION.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> x[i];
    solve();
}

