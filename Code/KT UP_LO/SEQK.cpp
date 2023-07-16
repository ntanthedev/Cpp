#include<bits/stdc++.h>
using namespace std;
long long a[100009], n, k, vt1 = 0, vt2 = 0;
map<long long, long long>M;
int main()
{
    freopen("SEQK.inp","r",stdin);
    freopen("SEQK.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(M[a[i]] == 0)
            M[a[i]] = i;
    }
    for(int i = n; i >= 1; i--)
    {
        if(M[a[i] - k] > 0 && M[a[i] - k] != i)
        {
            vt1 = M[a[i] - k];
            vt2 = i;
            break;
        }
    }
    cout<<vt2<<" "<<vt1;

}
