#include<bits/stdc++.h>
#define tag "GAS"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n, k, res = 0, a[N];
deque<ll> dq;
void solve(){
    for(int i = 1; i <= k; i++)
        dq.push_back(a[1]);
    for(int i = 2; i <= n; i++){
        res += dq.front(); //cout<<dq.front()<<" ";
        dq.pop_front();
        while(!dq.empty() && dq.back() > a[i])
            dq.pop_back();
        while(dq.size() < k)
            dq.push_back(a[i]);
    }
        res += dq.front(); //cout<<dq.front()<<" ";
        dq.pop_front();
    cout<<res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
}
