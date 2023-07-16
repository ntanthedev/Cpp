#include<bits/stdc++.h>
using namespace std;
long long S, v1, v2;
long double t, res = -1.000;
int main()
{
    cin.tie(NULL);
    freopen("MEET3.inp","r",stdin);
    freopen("MEET3.out","w",stdout);
    cin>>v1>>v2>>S;
    if(2*v1 < S) //gap nhau
    {
        S = S - 2*v1;
        t =  (double (S))/(v1+v2);
        res = 2*v1 + t*v1;
    }
    if(res == -1)
        cout<<res;
    else{
        cout<<fixed<<setprecision(3);
        cout<<res;
    }
}
