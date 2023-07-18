#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll p = 9, res, kt;
ll n;
void slove(){
    while(n > 0){
        res += n;
        n = n-p;
        p = p*10;
    }
    cout<<res;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("code.inp","r",stdin);
    freopen("code.out","w",stdout);    
    cin>>n;
    slove();
}