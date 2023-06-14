#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, k, a[50], dem = 0, x[50], sum;
void output(){
    sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a[i]*x[i];
    if(sum == k)
        dem++;
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
    freopen("SOLIEU.inp","r",stdin);
    freopen("SOLIEU.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    tim(1);
    cout<<dem;
}