#include<bits/stdc++.h>


const long long N = 1e6+9;
using namespace std;

typedef long long ll;

ll n;

void solve(ll x) {
    if(x > 1) 
        solve(x / 2);
    cout << x % 2 ;
}

#define task "CTBIT"
signed main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    while(cin >> n) {
        solve(n);
        cout << '\n';
    }
}