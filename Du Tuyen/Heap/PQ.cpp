#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll T, gmax = -1, x;
char s;
priority_queue<ll>q;
void solve(){
    while(T--){
        cin>>s;
        if(s=='+'){
            cin>>x;
            q.push(x);
        }
        else{
            if(!q.empty())
                gmax = q.top();
            while(!q.empty() && q.top() == gmax){
                q.pop();
            }
        }
    }
    queue<ll>qq;
    while(!q.empty()){
        if(qq.empty() || qq.back() != q.top())
            qq.push(q.top());
        q.pop();
    }
    cout<<qq.size()<<'\n';
    while(!qq.empty()){
        cout<<qq.front()<<" ";
        qq.pop();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("PQ.inp","r",stdin);
    freopen("PQ.out","w",stdout);
    cin>>T;
    solve();
}