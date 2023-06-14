#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], s[N], gmax = 1;
void solve(){
    for(int i = 1; i < n; i++){
        for(int j = n; j > i; j--){
            if((s[j] - s[i-1])%2 != 0)
                continue;
            ll mid = (s[j] - s[i-1])/2;
            ll x = *lower_bound(s+1, s+1+n, mid);
            if(x == mid){
                gmax = j - i + 1;
                break;
                cout<<"i: "<<i<<'\n';
                cout<<"j: "<<j<<'\n';
                cout<<"gmax: "<<gmax<<'\n';
                cout<<"mid: "<<mid<<'\n';
                cout<<"x: "<<x<<'\n';
            }
        }
    }
    //cout<<gmax;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n; s[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
    }
    solve();
}