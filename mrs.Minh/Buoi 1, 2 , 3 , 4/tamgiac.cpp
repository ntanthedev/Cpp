#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
long double a, b, c, s;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("tamgiac.inp","r",stdin);
    freopen("tamgiac.out","w",stdout);
    cin>>a>>b>>c;
    if(a+b <= c || a+c <= b || b+c <= a)
        cout<<"NO";
    else{        
        cout<<a+b+c<<" ";
        cout<<fixed<<setprecision(3);
        s = sqrt((a+b+c)*(a+b-c)*(b+c-a)*(c+a-b));
        cout<<s/4;
    }
}