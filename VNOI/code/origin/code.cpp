#include<bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
   freopen("code.inp","r",stdin);
   freopen("code.out","w",stdout);
      long long m, n, a;
      cin>>m>>n>>a;
      if(m%a > 0)
        m = int(m)/a + 1;
    else 
        m = m/a;
    if(n%a > 0)
        n = int(n)/a + 1;
    else
        n = n/a;
    cout<<n*m;
}
