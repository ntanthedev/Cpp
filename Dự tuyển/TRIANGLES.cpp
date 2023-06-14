#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll a[N], n, m = 0, b[N], ans = 0;
map<ll, ll>M;
void solve(){
    sort(b+1, b+1+m);
    for(int i = 1; i <= m; i++)
        cout<<"\ni: "<<i<<" b[i]: "<<b[i]<<" M[b[i]] "<<M[b[i]];
    for(int i = 1; i < m; i++){
        if(M[b[i]] >= 2){
            ans += M[b[i]]-2;
            ll t = lower_bound(b+i+1, b+1+m, b[i]*2) - b - 1; cout<<"\nt: "<<t;
            ans += t-i; cout<<"\ni: "<<i<<"\nt-i: "<<t-i<<'\n';
        }
        for(int j = i+1; j <= m; j++){
            ll x = lower_bound(b+j+1, b+1+m, b[i]+b[i]) - b - 1;
            ans += x - j;
        }
    }
    cout<<"ans: "<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("TRIANGLES.inp","r",stdin);
    //freopen("TRIANGLES.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(M[a[i]] == 0)
            b[++m] = a[i];
        M[a[i]]++;
    }
    for(int i = 1; i <= m; i++)
        cout<<b[i]<<" ";
    solve();
}
