#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll T, n, x, y, res;
void solve(){
    for(int i = 1, x = 1; i <= n; i++){
        cin>>res;
        x *= res;
    }
    for(int i = 1, y = 1; i <= n; i++){
        cin>>res;
        y *= res;
    }
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n;
        solve();
    }
}