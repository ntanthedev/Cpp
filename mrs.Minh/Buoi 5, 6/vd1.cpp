#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
struct sx
{
    int a, b;
};
sx c[N];
bool cmp(pt x, pt y)
{
    return (x.a < y.a || (x.a == y.a && x.b > y.b));
}
ll n;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>c[i].a;
    for(int i = 1; i <= n; i++)
        cin>>c[i].b;
    sort(c+1,c+1+n,cmp);
    for(int i = 1; i <= n; i++)
        cout<<c.a<<" "<<c.b<<'\n';
}