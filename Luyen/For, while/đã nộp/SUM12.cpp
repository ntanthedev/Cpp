#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    double S = 0, j = 0, i = 1;
    cin >> n;
    for(;i <= n; i++)
    {
        S += 1/((double)i+j);
        j += i;

    }
    cout<<fixed<<setprecision(3);
    cout<<S;
}
