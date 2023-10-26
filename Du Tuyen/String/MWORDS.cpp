#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("MWORDS.inp","r",stdin);
    freopen("MWORDS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);
    long long gmax = 0;
    while(cin>>s)
        if(s.size() > gmax)
            gmax = s.size();
    cout<<gmax;
}
