#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("COMPSTR.inp","r",stdin);
    freopen("COMPSTR.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);      cout.tie(NULL);
    cin>>s;
    for(int i = 0; i < s.size(); i++)
        while(s[i] == s[i+1])
            s.erase(i, 1);
    cout<<s;
}
