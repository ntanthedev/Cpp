#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll a[N], x[N], n, k, sum;
void output(){
    sum = a[1];
    for(int i = 2; i <= n; i++){
        if(x[i] == 0)
            sum += a[i];
        else
            sum -= a[i];
    }
    if(sum == k)
        for(int i = 2; i <= n; i++)
            if(x[i] == 0)
                cout<<"+";
            else
                cout<<"-";
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
    freopen("EXPR.inp","r",stdin);
    freopen("EXPR.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    //sum = a[1];
    tim(2);
}