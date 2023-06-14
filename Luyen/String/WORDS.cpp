#include<bits/stdc++.h>
using namespace std;
long long i = 1;
string a[1000022], s;
int main()
{
    freopen("WORDS.inp","r",stdin);
    freopen("WORDS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);     cout.tie(NULL);
    while(cin>>s)
        a[i++] = s;
    for(int j = 1; j <= i - 1; j++)
        cout<<a[j]<<'\n';
}
