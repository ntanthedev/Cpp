#include<bits/stdc++.h>

using namespace std;

const long long N = 2e5+9;

int n, a[N]; 

int main()
{
    freopen("SUM2N.inp","r",stdin);
    freopen("SUM2N.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a+1, a+1+n);
    cout << a[n] + a[n-1];
}