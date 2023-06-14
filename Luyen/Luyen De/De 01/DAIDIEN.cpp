#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], t = 0, gmax = 0, vt1 = 1, vt2;
map<long long, long long>D;
map<long long, long long>C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DAIDIEN.inp","r",stdin);
    freopen("DAIDIEN.out","w",stdout);
    cin>>n;
    D[t] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i] > 0) t++;
        if(a[i] < 0) t--;
        if(D[t] == 0)
            D[t] = i;
        else
        {
            C[t] = i;
            if(C[t] - D[t] + 1 > gmax)
            {
                gmax = C[t] - D[t] + 1;
                vt1 = D[t] + 1; vt2 = C[t];
            }
        }
    }
    if(gmax > 0)
        cout<<vt1<<" "<<vt2;
    else
        cout<<"0";
}
/*#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], gmax = LLONG_MIN, l, r, DA[1000009], DD[1000009];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DAIDIEN.inp","r",stdin);
    freopen("DAIDIEN.out","w",stdout);
    cin>>n;
    DA[0] = 0;
    DD[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        DA[i] = DA[i - 1];
        DD[i] = DD[i - 1];
        if(a[i] < 0)
            DA[i]++;
        if(a[i] > 0)
            DD[i]++;
    }
    for(int i = 1; i < n; i++)
        for(int i = i + 1; i <= n; i++)
            if(DA[j] - D)
}*/
/*#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], t = 0, gmax = 0, vt1 = 1, vt2;
map<long long, long long>D;
map<long long, long long>C;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DAIDIEN.inp","r",stdin);
    freopen("DAIDIEN.out","w",stdout);
    cin>>n;
    D[t] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i] > 0) t++;
        if(a[i] < 0) t--;
        if(D[t] == 0)
            D[t] = i;
        else
        {
            C[t] = i;
            if(C[t] - D[t] + 1 > gmax)
            {
                gmax = C[t] - D[t] + 1;
                vt1 = D[t] + 1; vt2 = C[t];
            }
        }
    }
    if(gmax > 0)
        cout<<vt1<<" "<<vt2;
    else
        cout<<"0";
}
*/
///memset(LD, -1, sizeof(LD))
