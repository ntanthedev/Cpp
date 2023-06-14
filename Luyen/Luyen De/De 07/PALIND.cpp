#include<bits/stdc++.h>
using namespace std;
string s;
long long n, d = 0, l, r, vt1, vt2, gmax = 0;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("PALIND.inp","r",stdin);
    freopen("PALIND.out","w",stdout);
    cin>>s;
    getline(cin,s);
    n = s.size();
    for(int i = 0; i < n; i++)
    {
        if(s[i] == s[i+1])
        {

        }
    }
}



/*
#include<bits/stdc++.h>
using namespace std;
long double a,gmax=LLONG_MIN,ld,lc;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("palind.inp","r",stdin);
    freopen("palind.out","w",stdout);
    string s;
    getline(cin,s);
   for(int i=1;i<=s.size();i++)
    {
        if(s[i]==s[i+1])
        {
            a=1;
            for(int j=1;j<=i;j++)
            {
                if(s[i-j]==s[i+1+j])
                    {
                        a=j+1;
                    }
                else if(a>gmax)
                {
                        gmax=a;
                        ld=i;
                        lc=j;
                        break;
                }
            }
        }
    }
    for(int i=ld-lc+1;i<=ld+lc;i++)
        cout<<s[i];
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
char a[5068];
int n,i,k,li,lj,tg,d;
void tim(char a[])
{
    n=strlen(a);
    for(i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            k=i+1;
            while(a[k-d-1]==a[k+d]&&k>d) d++;
            if(d>tg)
            {
                tg=d;
                li=k-tg;
                lj=k+tg-1;
            }
        }
    }
    if(lj==0)
    {
        return;
    }
    for(i=li;i<=lj;i++)
        cout<<a[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>a;
    tim(a);
}
*/
