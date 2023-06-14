#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
vector<string>f(505);
string sumstr(string a, string b){
    while(a.size() < b.size()){
        a = "0"+a;
    }
    ll n = b.size(), t, nho = 0;
    string sum;
    sum.resize(n);
    for(int i = n-1; i >= 0; i--){
        t = (a[i]-'0') + (b[i]-'0') + nho;
        if(t >= 10){
            t = t%10;
            nho = 1;
        }
        else
            nho = 0;
        sum[i] = t + '0';
    }
    if(nho == 1)
        sum = "1"+sum;
    return sum;
}
void solve(){
    f[1] = f[2] = "1";
    for(int i = 3; i <= 500; i++){
        f[i] = sumstr(f[i-2], f[i-1]);
    }
    ll n;
    cin>>n;
    ll x;
    for(int i = 1; i <= n; i++){
        cin>>x;
        cout<<f[x]<<'\n';
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("STTMCO.inp","r",stdin);
    freopen("STTMCO.out","w",stdout);
    
    solve();
}