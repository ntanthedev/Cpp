#include<bits/stdc++.h>
#define tag "code"
#define ll long long 
const long long N = 1e6+9;
using namespace std;
ll n;
void solve(){
    cout<<(n+1)*(n+1)-1;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n;
    solve();
}