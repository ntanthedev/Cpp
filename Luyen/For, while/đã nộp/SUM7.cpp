#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long S = 0, n, i = 1, j;
    cin>>n;
    while(i<=n)
    {
        if(i%2 == 0)
        {
            j = i*(-1);
            S += j;
        }
        else
        {
            S+= i;
        }
        i++;
    }
    cout<<S;
}
