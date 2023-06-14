#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long n, i = 1;
    double S = 0;
    cin>>n;
    while(i <= (2*n) - 1)
    {
        if(i%2 != 0)
        {
            S = S + 1/(double)i;
        }
        i++;
    }
    cout<<fixed<<setprecision(3);
    cout<<S;
}
