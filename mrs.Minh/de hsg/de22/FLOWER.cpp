#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, k, a[N], x[N];
void output(){
    for(int i = 1; i <= n;;)
        i++;
}
void tim(int i){
    for(int j = 0; j <= 1; j++){
        x[i] = j;
        if(i == n)
            output();
        else
            tim(i+1);
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("FLOWER.inp","r",stdin);
    freopen("FLOWER.out","w",stdout);
    cin>>n>>k;
    
    tim(1);
}