#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define pob pop_back
const int N = 1e6+9;
using namespace std;
ll m, n, ans = 0, L[N], R[N], h[N], x, gmax = 0;
vector<ll> vt;
bool b[1000000];
void sang(){
    memset(b, true, sizeof(b));
    b[0] = false;
    b[1] = false;
    for(int i = 2; i <= sqrt(10000000); i++)
        if(b[i])
            for(int j = i*i; j <= 10000000; j += i)
                b[j] = false;
}
void solve(){
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(b[x])
            h[i]++;
        else
            h[i] = 0;
    }
    vt.clear(); vt.pb(0);
    for(int i = 1; i <= n; i++){
        while(!vt.empty() && h[vt.back()] >= h[i])
            vt.pob();
        L[i] = vt.back();
        vt.pb(i);
    }
    vt.clear(); vt.pb(0);
    for(int i = n; i >= 1; i--){
        while(!vt.empty() && h[vt.back()] >= h[i])
            vt.pop_back();
            if(vt.back()==0){
                R[i] = n+1;
                vt.pb(i);
                continue;
            }
        R[i] = vt.back();
        vt.pb(i);
    }
    //giai quyet bai toan
    for(int i = 1; i <= n; i++){
        ll t = min(h[i], R[i] - L[i] - 1);
        gmax = max(gmax, t*t);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("PSQ.inp","r",stdin);
    freopen("PSQ.out","w",stdout);
    sang(); 
    memset(h, 0, sizeof(h));
    cin >> m >> n; h[n+1] = 0;
    for(int i = 1; i <= m; i++){
        solve();
    }
    cout<<gmax;
}