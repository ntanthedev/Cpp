#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    long double i = 1, S = 0;
    cin>>n;
    for(;i<=n; i++)
    {
        S = S + 1/i;

    }
    cout<<fixed<<setprecision(3);
    cout<<S;
}
