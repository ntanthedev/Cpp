#include<bits/stdc++.h>
using namespace std;
long long n,i,a,b,sc,s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    freopen("kehoachnho.inp","r",stdin);
    freopen("kehoachnho.out","w",stdout);

    cin>>a>>b>>n;
    sc=a+(n-1)*b;
    s=(sc+a)*n/2;
    cout<<s;
}
