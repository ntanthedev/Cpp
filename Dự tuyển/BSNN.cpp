#include<bits/stdc++.h>
#define tag "BSNN"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n;
string s;
unordered_map<int, bool>M;
bool check(int x){
    while(x > 0){
        int t = x%10;
        if(!M[t])
            return false;
        x /= 10;
    }
    return true;
}
void solve(){
    for(int i = 0; i < s.size(); i++)
        M[s[i] - '0'] = true;
    ll t = 1, k;
    while(t <= n){
        k = n*t;
        if(check(k)){
            cout<<k;
            return;
        }
        t++;
    }
    cout<<0;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> s;
    solve();
}