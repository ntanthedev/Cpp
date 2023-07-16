#include<bits/stdc++.h>
using namespace std;
long long a[100022];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SORT.inp","r",stdin);
    freopen("SORT.out","w",stdout);
    long i = 1;
    while(cin>>a[i])
        i++;
    sort(a+1, a+i);
    for(int j = 1; j <= i-1; j++)
        cout<<a[j]<<'\n';
}
