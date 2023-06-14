#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, res = 0;
priority_queue<ll>a, b;
void solve(){
    while(!a.empty() && !b.empty()){
        if(a.top() > b.top())
            a.pop();
        if(a.top() == b.top()){
            res += 1;
            a.pop();
            b.pop();
        }
        if(a.top() < b.top()){
            res += 2;
            a.pop();
            b.pop();
        }
    }
    cout<<res;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++){
        ll x, y;
        cin>>x>>y;
        a.push(x);
        b.push(y);
    }
    solve(); 
}