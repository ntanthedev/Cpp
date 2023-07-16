#include<bits/stdc++.h>
using namespace std;
long long a[100000099], n;
int main ()
{
    freopen("MAXSEQ.inp", "r", stdin);
    freopen("MAXSEQ.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; ++i)
    cin>>a[i];

    long long max;
    max = a[1];
    for(int i = 1; i <= n; ++i)
        if(a[i] > max)
            max = a[i];
    cout<<max;

}
