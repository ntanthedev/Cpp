#include<bits/stdc++.h>
using namespace std;
long long n;
struct stb
{
    unsigned long long gt;
    int vt;
};
stb a[100022];
bool cmp(stb S1, stb S2)
{
    return(S1.gt < S2.gt || (S1.gt == S2.gt && S1.vt < S2.vt));
}
int main()
{
    freopen("STABLE.inp","r",stdin);
    freopen("STABLE.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);      cout.tie(NULL);
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
         cin>>a[i].gt;
         a[i].vt = i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1; i <= n; i++)
        cout<<a[i].vt<<" ";
}
