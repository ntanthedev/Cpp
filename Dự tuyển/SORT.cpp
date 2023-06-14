#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
priority_queue<int, vector<int>, greater<int>>q;
bool check(ll x){
    ll res = 1;
    for(int i = 2; i <= sqrt(x); i++)
        if(x%i == 0){
            res += i;
            if(i != x/i)
                res += x/i;
        }
    if(res == x)
        return true;
    return false;
}
void solve(){
    ll n, x;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x;
        if(check(x))
            q.push(x);
    }
    if(q.size() == 0)
        cout<<0;
    else
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("SORT.inp","r",stdin);
    //freopen("SORT.out","w",stdout);

    solve();
}
