#include<bits/stdc++.h>
using namespace std;
unsigned long long a[100022], n, Q, x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("S03.inp","r",stdin);
    freopen("S03.out","w",stdout);
    cin>>n>>Q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    for(int i = 1; i <= Q; i++)
    {
        cin>>x;
        int p = lower_bound(a+1,a+1+n,x) - a;
        if(a[p] == x)
            cout<<(upper_bound(a+1,a+1+n,x) - a) - (lower_bound(a+1,a+1+n,x) - a)<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}
