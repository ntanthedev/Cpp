#include<bits/stdc++.h>
using namespace std;
long long n = 1;
struct MyType
{
    long long gt;
    int vt;
};
MyType a[100009];
bool cmp(MyType s1, MyType s2)
{
    if(s1.gt < s2.gt)
        return true;
    if(s1.gt == s2.gt && s1.vt < s2.vt)
        return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    freopen("SORT2.inp","r",stdin);
    freopen("SORT2.out","w",stdout);
    while(cin>>a[n].gt)
    {
        a[n].vt = n;
        n++;
    }
    sort(a+1, a+n, cmp);
    for(int i = 1; i <= n-1; i++)
        cout<<a[i].vt<<" ";
}
