#include<bits/stdc++.h>
using namespace std;
long long a[1000009], n, gmax = LLONG_MAX, vt;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DP04.inp","r",stdin);
    freopen("DP04.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] < gmax)
            gmax = a[i];
    }
    int d = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] == gmax)
            d++;
    cout<<d;
}
