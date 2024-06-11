#include<bits/stdc++.h>
#define ll long long
#define xau "SEQDK"
const int N = 1e6+9;
using namespace std;
ll n, k, a[N], smin[N], s[N], s1[N], s2[N], sumarr = 0, f[1009][1009][2];

void sub1(){
    ll ans = 0, res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res + a[i], a[i]);
        ans = max(ans, res);
    }
    cout<<ans;
}
void sub2(){
    s[0] = 0, s1[0] = 0;
    for(int i = 1; i <= n; i++){
        s[i] = s[i-1] + a[i];
        smin[i] = min(smin[i-1], s[i]);
        s1[i] = max(s1[i-1], s[i] - smin[i]);
    }
//    cout<<"s[i]: ";for(int i = 1; i <= n; i++) cout<<s[i]<<" "; cout<<'\n';
//    cout<<"smin[i]: ";for(int i = 1; i <= n; i++) cout<<smin[i]<<" "; cout<<'\n';
//    cout<<"s1[i]: ";for(int i = 1; i <= n; i++) cout<<s1[i]<<" "; cout<<'\n';
    s[n+1] = 0, s2[n+1] = 0;
    memset(smin, 0, sizeof(smin));
    for(int i = n; i >= 1; i--){
        s[i] = s[i+1] + a[i];
        smin[i] = min(smin[i+1], s[i]);
        s2[i] = max(s2[i+1], s[i] - smin[i]);
    }
//    cout<<"s[i]: ";for(int i = 1; i <= n; i++) cout<<s[i]<<" "; cout<<'\n';
//    cout<<"smin[i]: ";for(int i = 1; i <= n; i++) cout<<smin[i]<<" "; cout<<'\n';
//    cout<<"s2[i]: ";for(int i = 1; i <= n; i++) cout<<s2[i]<<" "; cout<<'\n';
    ll gmax = 0;
    for(int i = n; i >= 1; i--)
        gmax = max(gmax, s1[i-1] + s2[i]);
    cout<<gmax;
}
void sub3(){
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++)
            f[i][j][0] = f[i][j][1] = -1e17;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= k; j++) {
            f[i][j][0] = max(f[i-1][j][0], f[i-1][j][1]);
            f[i][j][1] = max(max(f[i-1][j][1], f[i-1][j-1][0]), f[i-1][j-1][1]) + a[i];
        }
    ll ans = 0;
    for(int i = 1; i <= n; ++i)
        ans = max(ans, f[i][k][1]);
    cout<<ans;
}
void subbruh(){
    ll gmin = 234234234;
    for(int i = 1; i <= n; i++)
        gmin = min(gmin, a[i]);
    cout<<sumarr-gmin;
}
void subbruhhh(){
    sort(a+1, a+1+n);
    ll bruh = 0;
    for(int i = 1; i <= n-k; i++){
        bruh += a[i];
    }
    cout<<sumarr-bruh;
}
void solve(){
    if(k == n)
        cout<<sumarr;
    else if (k == n-1)
        subbruh();
    else if(k == 1)
        sub1();
    else if(k == 2)
        sub2();
    else if(k == 3)
        sub3();
    else
        subbruhhh();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sumarr += a[i];
    }
    solve();
}
