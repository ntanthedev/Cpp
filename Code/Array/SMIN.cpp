#include<bits/stdc++.h>
using namespace std;
unsigned long long a[100000000], n;
int main ()
{
    freopen("SMIN.inp","r",stdin);
    freopen("SMIN.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; ++i)
        cin>>a[i];
    sort(a + 1, a + 1 + n);
    long long i = 1, G;
    while(i <= n + 1)
    {
        if(i != a[i])
            {
                G = i;
                break;
            }
        i++;
    }
    cout<<G;
}
