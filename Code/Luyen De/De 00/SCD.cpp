#include<bits/stdc++.h>
using namespace std;
unsigned long long a, b, S = 0, gmin;
int main()
{
    freopen("SCD.inp","r",stdin);
    freopen("SCD.out","w",stdout);
    cin.tie(NULL);
    cin>>a>>b;
    gmin = min(a, b);
    if(a%gmin == 0 && b%gmin == 0)
        S+= gmin;
    for(int i = 1; i <= gmin/2; i++)
    {
        if(a%i == 0 && b%i == 0)
            S+= i;
    }
    cout<<S;
}
