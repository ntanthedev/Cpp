#include<bits/stdc++.h>
using namespace std;
long long n, S = 0, a[1000009], gmax, l = 0, r = 0;
map<long long, long long>D;
map<long long, long long>C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SUBZERO.inp","r",stdin);
    freopen("SUBZERO.out","w",stdout);
    cin>>n;
    D[S] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        S += a[i];
        if(D[S] == 0)
            if(S == 0)
                D[S] = 0;
            else
                D[S] = i;
        if(D[S] != 0 || S == 0)
        {
            C[S] = i;
            if((C[S] - D[S] + 1) > gmax)
                {
                    gmax = C[S] - D[S] + 1;
                    l = D[S] + 1;
                    r = C[S];
                }
        }
    }
    cout<<l<<" "<<r;
}
/*#include<bits/stdc++.h>
using namespace std;
long long n, S = 0, a[1000009], gmax, l = 0, r = 0;
map<long long, long long>D;
map<long long, long long>C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SUBZERO.inp","r",stdin);
    freopen("SUBZERO.out","w",stdout);
    cin>>n;
    D[S] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        S += a[i];
        if(D[S] == 0)
            if(S == 0)
                D[S] = 0;
            else
                D[S] = i;
        if(D[S] != 0 || S == 0)
        {
            C[S] = i;
            if((C[S] - D[S] + 1) > gmax)
                {
                    gmax = C[S] - D[S] + 1;
                    l = D[S] + 1;
                    r = C[S];
                }
        }
    }
    cout<<l<<" "<<r;
}
*/
