#include<bits/stdc++.h>
#define tag "SUMS"
#define ll long long 
const long long N = 1e6+9;
using namespace std;
ll n;
void sub1(){
    ll res = 0;
    for(ll i = 1; i <= n; i++){
        res += (i+1)*(i+1) - i*i;
    }
    cout << res;
}
void sub2(){
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
    if(n <= 1e6)
        sub1();
    else
        sub2();
}