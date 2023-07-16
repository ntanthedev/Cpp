#include<bits/stdc++.h>
using namespace std;
long long dc = 0, ds = 0;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("CNCH4.inp","r",stdin);
    freopen("CNCH4.out","w",stdout);
    getline(cin,s);
    for(int i = 0; i < s.size(); i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            dc++;
        if(s[i] >= '0' && s[i] <= '9')
            ds++;
    }
    cout<<dc<<" "<<ds;
}
