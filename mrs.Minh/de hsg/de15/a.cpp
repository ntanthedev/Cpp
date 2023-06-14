#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const long long N = 1e6+9;
ll x, n, flag = 0;
map<ll,ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        M[x]++;
        if(M[x] == 3){
            cout<<x<<" ";
            M[x] = 0;
            flag = 1;
        }
    }
    if(flag == 0)
        cout<<0;
}