#include<bits/stdc++.h>
#define tag "BCARO"
#define ll long long
#define pb push_back
#define pob pop_back
const int N = 1e3+9;
using namespace std;
int a[N][N], n, m, L[N], R[N], h[N], f[N][N], gmax;
vector<int> vt;
void solve(){    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] != a[i][j+1] && a[i][j] != a[i+1][j] && a[i][j] == a[i+1][j+1])
                f[i][j] = 1;
            else
                f[i][j] = 0;
        }
    }
    //solve with stack
    memset(h, 0, sizeof(h));
    for(int j = 1; j <= m; j++){
        for(int i = 1; i <= n; i++){
            if(f[j][i] == 1) 
                h[i]++;
            else 
                h[i] = 0;
        }
        vt.clear();
        vt.pb(0);        
        for(int i = 1; i <= n; i++){
            while(!vt.empty() && h[vt.back()] >= h[i])
                vt.pob();
            L[i] = vt.back();
            vt.pb(i);
        }
        vt.clear();
        vt.pb(0);
        for(int i = n; i >= 1; i--){
            while(!vt.empty() && h[vt.back()] >= h[i])
                vt.pob();
            if(vt.back() == 0){
                R[i] = n+1;
                vt.pb(i);
                continue;
            } 
            R[i] = vt.back();
            vt.pb(i);
        }
        for(int i = 1; i <= n; i++){
            int t = (R[i] - L[i])*(h[i]+1);
            gmax = max(gmax, t);
        }
    }
    cout<<gmax;
}
//a[i][j] != a[i][j-1] && a[i][j] != a[i][j+1] && a[i][j] != a[i-1][j] && a[i][j] != a[i+1][j]
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    if(a[1][1] == 1) 
        a[0][1] = a[1][0] = 0;
    else 
        a[0][1] = a[1][0] = 1;
    solve();
}   