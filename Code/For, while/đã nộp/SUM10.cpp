#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i = 1;
    double S = 0;
    cin>>n;
    while( i <= n )
    {
        S += 1/((double)i*i);
        i++;
    }
    cout<<fixed<<setprecision(3);
    cout<<S;
}
