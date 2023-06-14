#include<bits/stdc++.h>
using namespace std;
long long a[100022], n, Q, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    freopen("S02.inp","r",stdin);
    freopen("S02.out","w",stdout);
    cin>>n>>Q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    for(int i = 1; i <= Q; i++)
    {
        cin>>x;
        int q = lower_bound(a+1, a+1+n, x) - a;
        if(q > n)
            cout<<"NO"<<'\n';
        else
            cout<<a[q]<<'\n';
    }
}
