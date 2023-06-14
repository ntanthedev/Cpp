#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
#define fi first
#define se second
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, gmax = -1, res = 0;
pair<ll, ll>a[N];
void solve(){
    ll rb = -1;
    for(int i = 1; i <= n; i++){
        cin>>a[i].fi>>a[i].se;
        if(a[i].fi <= rb){
            res++;
            rb = a[i].fi;
        }
        else{
            res = 1;
            rb = a[i].se;
        }
        gmax = max(res, gmax);
    }
    cout<<gmax;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    solve();
}