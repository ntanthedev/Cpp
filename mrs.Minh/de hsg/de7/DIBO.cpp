#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll m, n;

void slove(){
    for(int i = n/2; i <= n; i++){
        if(i%m == 0)
            cout<<i;
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DIBO.inp","r",stdin);
    freopen("DIBO.out","w",stdout);
    cin>>n>>m;    
    for(int i = n/2; i <= n; i++){
        if(i%m == 0){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    //slove();
}