#include<bits/stdc++.h>
using namespace std;
long long a[100009], Q, x, n;
int main()
{
    freopen("S01.inp","r",stdin);
    freopen("S01.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>Q;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    for(int i = 1; i <= Q; i++)
    {
        cin>>x;
        if(binary_search(a+1, a+1+n, x) == true)
            cout<<"1"<<'\n';
        else
            cout<<"0"<<'\n';
    }
}
