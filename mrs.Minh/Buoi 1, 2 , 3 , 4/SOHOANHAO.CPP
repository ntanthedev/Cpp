#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, s = 1;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("sohoanhao.inp","r",stdin);
    freopen("sohoanhao.out","w",stdout);
    cin>>n;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            s += i;
            if(n%(n/i) == 0 && n/i != i)
                s += n/i;
        }
    }
    if(s == n)
        cout<<"YES";
    else    
        cout<<"NO";
}