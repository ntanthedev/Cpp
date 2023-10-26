#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], m, n, cnt = 0;
deque<ll>dq;

void solve(){
    for(int i = 1; i <= n; i++){
        dq.push_back(a[i]);
    }
    while(!dq.empty()){
        if(dq.front() + dq.back() <= m && dq.size() != 1){
            cnt++;
            dq.pop_back();
            dq.pop_front();
        }
        else{
            cnt++;
            dq.pop_back();
        }
    }
    cout<<cnt;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("BICYCLES.inp","r",stdin);
    //freopen("BICYCLES.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    solve();
}