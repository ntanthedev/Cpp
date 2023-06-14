#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll h[N], n, m, R, x, gmax = LLONG_MIN, L[N];
vector<int>vt;
// void update(ll x){
//     if(x > gmax)
//         gmax = x;
// }
void findrect(){
    vt.resize(0);
    vt.push_back(0);
    for(int i = 1; i <= n; i++){
        while (h[vt.back()] >= h[i])
            vt.pop_back();
        L[i] = vt.back();
        vt.push_back(i);
    }
    vt.resize(0);
    vt.push_back(n+1);
    for(int i = n; i >= 1; --i){
        while(h[vt.back()] >= h[i])
            vt.pop_back();
        R = vt.back();
        if((R - L[i] - 1 + h[i])*2 > gmax){
            gmax = (R - L[i] - 1 + h[i])*2;
        }
        vt.push_back(i);
    }
}
void solve(){
    for(int i = 1; i <= n; i++){
        cin>>x;
        if(x == 0)
            h[i]++;
        else
            h[i] = 0;
        findrect();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen(".inp","r",stdin);
    //freopen(".out","w",stdout);
    cin>>m>>n;
    memset(h, 0, sizeof(h));
    h[0] = h[n+1] = -1;
    vt.reserve(N);
    for(int i = 1; i <= m; i++){
        solve();
    }
    cout<<gmax;
}