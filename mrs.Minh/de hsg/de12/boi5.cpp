#include <bits/stdc++.h>
using namespace std;
long long n,m,a[10],b[10],k;
int main()
{
    freopen("Boi5.inp","r",stdin);
    freopen("Boi5.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    //k=max(n,m);
    for(int i=1;i<=n;i++)
        a[i%5]++;
    for(int j=1;j<=m;j++)
      b[j%5]++;
     k=(a[0]*b[0])+(a[1]*b[4])+(a[2]*b[3])+(a[3]*b[2])+(a[4]*b[1]);
    cout<<k;
}