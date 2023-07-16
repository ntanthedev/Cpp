#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long N = 200;
ll m,  n, a[N], x[N], flag = 0;
void check(){
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(x[i] == 1)
            res += a[i];
    }
    if(res == m)
        flag = 1;
}
void tim(int i){
    for(int j = 0; j <= 1; j++){
        if(flag == 1)
            break;
        x[i] = j;
        if(i == n)
            check();
        else
            tim(i+1);
    }
}
void output(){
    if(flag == 1){
        cout<<"YES"<<'\n';
        for(int i = 1; i <= n; i++){
            if(x[i] == 1)
                cout<<i<<" ";
        }
    }
    else 
        cout<<"NO";
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("SUBSETSUM.inp","r",stdin);
    //freopen("SUBSETSUM.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    tim(1);
    output();
}