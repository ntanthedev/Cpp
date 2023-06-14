#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long m, n, x ;
    cin>>n>>m;
    if (m%2 == 0 || n%2 == 0)
    {
        if(m%2 != 0 && n%2 == 0)
            x = ((int)m/2 + 1)*(n/2);
         else if (m%2 == 0 && n%2 != 0)
            x = ((int)n/2 + 1) * (m/2);
        else
            x = (m/2)*(n/2);
    }
    else
        x = ((int)m/2 + 1)*((int)n/2 + 1);
   cout<<x;
}


