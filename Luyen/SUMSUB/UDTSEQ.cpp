#include<bits/stdc++.h>
using namespace std;
long long n, m, a[1000009], i, j, k;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    freopen("UDTSEQ.inp","r",stdin);
//    freopen("UDTSEQ.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i<= n; i++)
        a[i] = 0;
    for(int x = 1; x <= m; x++)
    {
        cin>>i>>j>>k;
        for(; i <= j; i++)
            a[i] += k;
    }
    for(int x = 1; x <= n; x++)
        cout<<a[x]<<" ";
}
