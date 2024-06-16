#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
void solve() {
    ll m;
    cin>>m;
    vector<ll>save;
    if(m%2==0)
    {
        save.push_back(2);
        while(m%2==0) m/=2;
    }
    for(ll i=3;i*i<=m;i+=2)
    {
        if(m%i==0)
        {
            save.push_back(i);
            while(m%i==0) m/=i;
        }
    }
    if(m>1) save.push_back(m);
    string ans;
    for(auto i:save)
    {
        //cout<<i<<" ";
        ll ii=i;
        ii%=26;
        ans.push_back('A'+ii);
    }
    sort(ans.begin(),ans.end());
    cout<<ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tests=1;
    while(tests--) {
        solve();
    }
}