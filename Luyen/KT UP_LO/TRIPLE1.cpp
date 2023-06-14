#include<bits/stdc++.h>
using namespace std;
long long n, a[100009], k, x, y, check;
map<long long, long long>M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TRIPLE1.inp","r",stdin);
    freopen("TRIPLE1.out","w",stdout);
    cin>>n;
    if(n <= 2){
        cout<<0<<" "<<0<<" "<<0;
        check = 1;}
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        M[a[i]] = i;
    }
    sort(a+1,a+1+n);
    for(int i = 1; i < n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            k = a[j] - a[i];
            if(M[a[j] + k]&& k != 0)
            {
                x = i; y = j; n = i;
            }
        }
    }
    if((a[x] == 0) && (a[y] == 0))
        if(check == 0)
            cout<<0<<" "<<0<<" "<<0;
        else
            cout<<a[x]<<" "<<a[y]<<" "<<a[y] + k;
}
