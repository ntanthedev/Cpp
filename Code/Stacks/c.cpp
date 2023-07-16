#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll Q, n, m, dem = 0, x[15], a[15];
//bool flag = false;
void check(){
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(x[i] == 1)
            res += a[i];
        if(x[i] == 2)
            res -= a[i];
        if(x[i] == 3)
            res *= a[i];
    }
    if(res%m == 0){
        dem++;
    }
}
void tim(int i){
    for(int j = 1; j <= 3; j++){
        x[i] = j;
        if(i == n)
            check();
        else
            tim(i+1);
    }
}
void solve(){
    dem = 0;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    x[1] = 1;
    tim(2);
    cout<<dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>Q;
    while(Q--)
        solve();
}