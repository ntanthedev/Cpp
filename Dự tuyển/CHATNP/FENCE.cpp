#include<bits/stdc++.h>


const long long N = 1e6+9;
using namespace std;

typedef long long ll;

ll n, k;
vector<ll> a;

void solve() {
    
}

#define task "FENCE"
signed main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    a.resize(n);
    for(auto &i : a)
        cin >> i;
    solve();
}