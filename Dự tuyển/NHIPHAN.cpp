#include<bits/stdc++.h>
#define tag "NHIPHAN"
#define ll long long 
const int N = 1e2+9;
using namespace std;
ll n, a[N], x[N];
void dmm(){
    for(int i = 1; i <= n; i++)
        cout<<x[i];
    cout<<'\n';
}
void solve(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n)
            dmm();
        else
            solve(i+1);
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
    
    solve(1);
}