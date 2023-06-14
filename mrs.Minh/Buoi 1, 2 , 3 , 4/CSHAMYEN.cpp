#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, m, a[N], M[N], gmax = 0;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("CSHAMYEN.inp","r",stdin);
    //freopen("CSHAMYEN.out","w",stdout);
    cin>>m>>n;
    memset(M,0,sizeof(M)); 
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        M[a[i]]+= a[i];
        if(M[a[i]] > gmax)
    }
    for(int i = 1; i <= N; i++){
        if(M[i] == gmax){
            cout<<i<<" "<<gmax;
            break;
        }
    }
}