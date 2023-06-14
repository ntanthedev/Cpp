#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
long long a[1000009], n, d = 2, gmax = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("DAYCON.inp","r",stdin);
    freopen("DAYCON.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    cin>>a[i];
    for(int i = 1; i < n; i++){
        if(a[i] - a[i-1] == a[i+1] - a[i])
            d++;
        else
            d = 2;
        gmax = max(gmax, d);
    }
    cout<<gmax;
}
