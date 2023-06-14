#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("TWGOATS.inp","r",stdin);
    freopen("TWGOATS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    long long t = 0, p = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '>')
            p++;
        else
        {
            if(p>0)
                p--;
            else
                t++;
        }
    }
    cout<<t+p;
}
