#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a, b, x;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("ptbac1.inp","r",stdin);
    //freopen("ptbac1.out","w",stdout);
    cin>>a>>b;
    cout<<fixed<<setprecision(5);
    if(b == 0){
        cout<<"VSN";
        return 0;
    }
    else if(a == 0)
        cout<<"VN";
    else
        cout<<(double(b)/a)*-1;        
}