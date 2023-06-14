#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
string s;
ll n, gmax = 0;
vector<bool>b(12, true);
void sang(ll x){
    b[0] = false;
    b[1] = false;
    for(int i = 2; i <= sqrt(x); i++)
        if(b[i])
            for(int j = i*i ; j <= x; j += i)
                b[j] = false;
}
void solve(){
    ll dp[N];
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(b[s[i] - '0'])
            dp[i] = dp[i-1]+1;
        else
            dp[i] = 0;
        gmax = max(dp[i], gmax);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("PASS.inp","r",stdin);
    freopen("PASS.out","w",stdout);
    sang(10);
    cin >> n;
    while(n--)
        solve();
    cout<<gmax;
}

