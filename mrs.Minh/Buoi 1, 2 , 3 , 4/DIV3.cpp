#include<bits/stdc++.h>
long long n, a[1000009], d1 = 0, d2 = 0, d3 = 0, dem;
using namespace std;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DIV3.inp","r",stdin);
    freopen("DIV3.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i]%3==0)
            d3++;
        if(a[i]%3==1)
            d1++;
        if(a[i]%3==2)
            d2++;
    }
    long long t = 0;
    for(int i = 1; i < d3; i++){
        t += i;
    }
    dem = t+(d2*d1);
    cout<<dem;
}
