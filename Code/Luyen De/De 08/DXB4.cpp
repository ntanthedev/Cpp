#include<bits/stdc++.h>
using namespace std;
long long n, gmax = 0, a[1000009], d = 0, s = 0;
map<long long, long long>D,C;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DXB4.inp","r",stdin);
    freopen("DXB4.out","w",stdout);
    cin>>n;
    D[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i]%2 == 0)
            s++;
        else
            s--;
        if(D[s] == 0)
            D[s] = 1;
        else
        {
            d += D[s];
            D[s]++;
        }    }
    cout<<d;
}
/*
#include<bits/stdc++.h>
using namespace std;
long long n, a[1000009], s = 0, d = 0, gmax = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DXB4.inp","r",stdin);
    freopen("DXB4.out","w",stdout);
    cin>>n;
    long long SL[1000009], SC[1000009];
    SL[0] = 0; SC[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        SL[i] = SL[i-1]; SC[i] = SC[i-1];
        if(a[i]%2 == 0)
            SC[i]++;
        else
            SL[i]++;
    }
    for(int i = 1; i <= n; i++)
        for(int j = i+1; j <= n; j++)
            if(SC[j] - SC[i-1] == SL[j] - SL[i-1])
                d++;
    cout<<d;
}
*/
/*for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(a[i]%2 == 0)
            s++;
        else
            s--;
        if(D[s] == 0 && s != 0)
            D[s] = i;
        else
        {
            C[s] = i;
            d++;
            if(C[s] - D[s] > gmax)
            {
                gmax = C[s] - D[s];
            }
        }
    }
    cout<<gmax;
    */
/*
long long sub1(long long d)
{
    long long SL[1000009], SC[1000009];
    SL[0] = 0; SC[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        SL[i] = SL[i-1]; SC[i] = SC[i-1];
        if(a[i]%2 == 0)
            SC[i]++;
        else
            SL[i]++;
    }
    for(int i = 1; i <= n; i++)
        if(SC[i] == SL[i])
            d++;
    return d;
}
*/
