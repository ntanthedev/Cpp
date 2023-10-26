#include<bits/stdc++.h>
#define tag "DINHDAY"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n, a[N];
queue<int> q;
void solve(){    
    for(int i = 1; i <= n; i++)
        if(a[i] > a[i-1] && a[i] > a[i+1])
            q.push(a[i]);
    cout<<q.size()<<'\n';
    if(q.size() > 0)
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n; 
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    solve();
}