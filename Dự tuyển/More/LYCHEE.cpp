#include<bits/stdc++.h>
#define tag "LYCHEE"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll s, dqsum = 0, ans = 0, n, a[N], k, h;
deque<int> dq;
void solve(){
    s = h*2/k+1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        dq.push_back(a[i]);
        dqsum += a[i];
        if(dq.size() > s){
            dqsum -= dq.front();
            dq.pop_front();
        }
        ans = max(ans, dqsum);
    }       
    //cout<<s<<'\n';
    cout<<ans;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> k >> h;
    solve();
}