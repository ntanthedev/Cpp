#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a, b;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("HCN.inp","r",stdin);
    //freopen("HCN.out","w",stdout);
    cin>>a>>b;
    cout<<(a+b)*2<<" "<<a*b;
}