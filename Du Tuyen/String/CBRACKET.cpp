#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("CBRACKET.inp","r",stdin);
    freopen("CBRACKET.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);      cout.tie(NULL);
    while(cin>>s)
    {
        int dem = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
                dem++;
            else
                dem--;
            if(dem < 0)
                break;
        }
        if(dem == 0)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
}
