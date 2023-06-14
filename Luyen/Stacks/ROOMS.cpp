#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 2*1e6+9;
ll n, id[N], kind[N], conf[N];
stack<int>st;
struct pt
{
    ll x, y;
};
pt a[N];
void solve(){
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("ROOMS.inp","r",stdin);
    freopen("ROOMS.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= 2*n; i += 2){
        cin>>a[i]>>a[i+1];
        s[i] = '(';
        s[i+1] = ']'; 
    }    
    solve();
}