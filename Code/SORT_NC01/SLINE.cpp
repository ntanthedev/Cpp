#include<bits/stdc++.h>
using namespace std;
long long gmax = 0, ld, lc, n;
struct sl
{
    long long d;
    long long c;
};
sl a[1000009];
bool cmp(sl a, sl b)
{
    return((a.d < b.d) || ((a.d == b.d)&&(a.c < b.c)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("SLINE.inp","r",stdin);
    //freopen("SLINE.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i].d>>a[i].c;
    sort(a+1, a+1+n, cmp);
    ld = a[1].d;    lc = a[1].c;
    gmax = lc - ld;
    for(int i = 2; i <= n; i++)
    {
        if(a[i].d > lc)
        {
            ld = a[i].d;
            lc = a[i].c;
            gmax = max(gmax, lc - ld);
        }
        else
        {
            lc = max(lc, a[i].c);
            gmax = max(gmax, lc - ld);
        }
    }
    cout<<gmax;
}
