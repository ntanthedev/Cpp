#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll n, a[N], b[N], pod = 0;
unordered_map<ll, bool>M;
void solve(){
    sort(b+1, b+1+pod);
    for(int i = 1; i <= n; i++){
        ll t = lower_bound(b+1, b+1+pod) - b;
        if(b[t] == a[i]){
            cout<<t-1<<" "<<
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("BIOP.inp","r",stdin);
    freopen("BIOP.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!M[a[i]])
            b[++pod] = a[i];
        M[a[i]] = true;
    }
    solve();
}

