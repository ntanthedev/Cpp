#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("CHKSTR.inp","r",stdin);
    freopen("CHKSTR.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);      cout.tie(NULL);
    int d, n;
    cin>>n;
    getline(cin, s);
    for(int k = 1; k <= n; k++)
    {
       getline(cin, s);
       d = 0;
       for(int i = 0; i < s.size(); ++i)
       {
           if(s[i] == '(')
                d++;
           if(s[i] == ')')
                d--;
           if(s[i] != '(' && s[i] != ')')
               d = -1;
           if(d < 0)
               break;
       }
       if(d == 0)
        cout<<"YES"<<'\n';
       else
        cout<<"NO"<<'\n';
    }
}
