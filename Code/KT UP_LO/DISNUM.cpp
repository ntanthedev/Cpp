#include<bits/stdc++.h>
using namespace std;
long long n, a[100009], dem = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DISNUM.inp","r",stdin);
    freopen("DISNUM.out","w",stdout);
    cin>>n;
    map<long long, long long>D;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        if(D[a[i]] == 0){
            dem++;
            D[a[i]]++};
    }
    cout<<dem;
}
