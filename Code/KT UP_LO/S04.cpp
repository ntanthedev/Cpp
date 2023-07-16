#include<bits/stdc++.h>
using namespace std;
long long a[100022], n, Q, L, R;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("S04.inp","r",stdin);
    freopen("S04.out","w",stdout);
    cin>>n>>Q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i = 1; i <= Q; i++)
    {
        cin>>L>>R;
        cout<<upper_bound(a+1,a+1+n,R) - lower_bound(a+1,a+1+n,L)<<'\n';
    }
}
