#include<bits/stdc++.h>
using namespace std;
int main ()
{
    long long m, n, k;
    cin>>m>>n>>k;
    if (m%k == 0 || n%k == 0)
    {
        if(m%k == 0 && n%k != 0)
            cout<<(m/k)*(n/k + 1);
        else if (m%k != 0 && n%k == 0)
            cout<<(m/k + 1)*(n/k);
        else
            cout<<(m/k )*(n/k );
    }
    else
        cout<<((int)m/k + 1)*((int)n/k + 1);


}
