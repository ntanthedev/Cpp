#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll s, a[30], x[30], n, sum;

void output(){
    for(int i = 1; i <= n; i++)
        cout<<x[i]*a[i]<<" ";
}
void check(){
    sum = 0;
    for(int i = 1; i <= n; i++){
        sum += x[i]*a[i];
        if(sum > s)
            break;
    }
    if(sum == s)
        output();
}
void tim(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n)
            check();
        else
            tim(i+1);
    }
}
void solve(){
    tim(i+1);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("ATM.inp","r",stdin);
    // freopen("ATM.out","w",stdout);
    cin>>n>>s;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}