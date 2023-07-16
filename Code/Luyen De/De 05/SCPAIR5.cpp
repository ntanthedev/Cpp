#include<bits/stdc++.h>
using namespace std;
string s, p;
long long l, dem = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("SCPAIR5.inp","r",stdin);
    freopen("SCPAIR5.out","w",stdout);
    getline(cin,s);
    getline(cin,p);
    l = s.size();
    for(int i = 0, j = l - 1;i <= l - 1; i++, j--)
    {
        if(s[i] == p[j])
            dem++;
    }
    cout<<dem;
}
