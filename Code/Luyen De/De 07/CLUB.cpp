#include<bits/stdc++.h>
using namespace std;
long long n, d = 0, a[1000009];
map<long long, long long>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("CLUB.inp","r",stdin);
    freopen("CLUB.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        M[a[i]]++;
        if(M[a[i]] == a[i])
        {
            d++;
            M[a[i]] = 0;
        }
    }
    cout<<d;
}
