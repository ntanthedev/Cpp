#include<bits/stdc++.h>
#define ll long long
#define xau "QBSEQ"
const int N = 1e6+9;
using namespace std;
ll a[N], n, m, s[N], gmax = -1;
map<ll, ll>M;
void sub1(){
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            if((s[j] - s[i-1])%m == 0){
                gmax = max(gmax, j-i+1);
                //cout<<i<<" "<<j<<'\n';
            }
    cout<<gmax;
}
void sub2(){
    s[0] = 0; M[0] = 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i]%m;
    }
//    for(int i = 1; i <= n; i++) cout<<a[i]%m<<" "; cout<<'\n';
//    for(int i = 1; i <= n; i++) cout<<s[i]<<" "; cout<<'\n';
//    for(int i = 1; i <= n; i++) cout<<s[i]%m<<" "; cout<<'\n';
    for(int i = 1; i <= n; i++){
        ans += M[s[i]%m]; //cout<<M[s[i]%m]<<" ";
        M[s[i]%m]++;
    }
    //cout<<'\n';
    cout<<ans;
}
void solve(){
    if(n <= 5*1e3)
        sub1();
    else
        sub2();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n >> m;
    solve();
}
