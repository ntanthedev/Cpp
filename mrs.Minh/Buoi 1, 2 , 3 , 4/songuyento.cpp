#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n;
bool check(ll x){
    if(x < 2)
        return false;
    for(int i = 2; i*i <= x; i++){
        if(x%i == 0)
            return false;
    }
    return true;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("songuyento.inp","r",stdin);
    freopen("songuyento.out","w",stdout);
    cin>>n;
    if(check(n))
        cout<<"YES";
    else
        cout<<"NO";
}