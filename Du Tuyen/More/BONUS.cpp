 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll f[N], g[N], n, a[N], L[N], R[N], res = 0;
vector<ll>vt;
void findmaxmin(){
    vt.resize(0);
    for(int i = n; i >= 1; i--){
        while(!vt.empty() && a[vt.back()] > a[i])
            vt.pop_back();
        if(vt.empty())   
            R[i] = n+1;
        else
            R[i] = vt.back();
        vt.push_back(i);
    }
    vt.resize(0);
    for(int i = 1; i <= n; i++){
        while(!vt.empty() && a[vt.back()] >= a[i])
            vt.pop_back();
        if(vt.empty())
            L[i] = 0;
        else
            L[i] = vt.back();
        vt.push_back(i);
    }

    for(int i = 1; i <= n; i++)
        f[i] = (i - L[i])*(R[i] - i);
    
    vt.resize(0);
    for(int i = 1; i <= n; i++){
        while(!vt.empty() && a[vt.back()] < a[i])
            vt.pop_back();
        if(vt.empty())
            L[i] = 0;
        else
            L[i] = vt.back();
        vt.push_back(i);
    }
    vt.resize(0);
    for(int i = n; i >= 1; i--){
        while(!vt.empty() && a[vt.back()] <= a[i])
            vt.pop_back();
        if(vt.empty())
            R[i] = n+1;
        else
            R[i] = vt.back();
        vt.push_back(i);
    }
    for(int i = 1; i <= n; i++)
        g[i] = (i - L[i]) * (R[i] - i);
}
void solve(){
    findmaxmin();
    for(int i = 1; i <= n; i++){
        res += a[i]*(g[i] - f[i]);
    }
    cout<<res;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "BONUS"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin>>n;
    vt.reserve(N);
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}