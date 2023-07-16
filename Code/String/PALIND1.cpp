#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("PALIND1.inp","r",stdin);
    freopen("PALIND1.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    while(getline(cin,s))
    {
        c = 1;
        for(int i = 0; i <= s.size()/2; i++)
        {
            if(s[i] != s[s.size()-i-1])
                {
                    c = 0;
                    break;
                }
        }
        if(c == 1)
            cout<<"TRUE"<<'\n';
        else
            cout<<"FALSE"<<'\n';
    }
}
