#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n;
bool b[1000001];
void sang(){
    memset(b, true, sizeof(b));
    b[0] = false;
    b[1] = false;
    for(int i = 2; i <= sqrt(1000000); i++){
        if(b[i] == true)
            for(int j = i*i; j <= 1000000; j += i)
                b[j] = false;
    }
}
void solve(){
    cin>>n;
    ll res = 0;
    sang();
    for(int i = 1; i <= n; i++){
        if(b[i] == true && b[n-i] == true){
            b[i] = false;    
            res++;
        }
    }
    if(b[n/2])
        cout<<res/2 - 1;
    else
        cout<<res/2;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("bai5.inp","r",stdin);
    freopen("bai5.out","w",stdout);
    
    solve();
}