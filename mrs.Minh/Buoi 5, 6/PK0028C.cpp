#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;

struct sx
{
    ll x, y, vt;
}
sx a[N];
bool cmp(sx c, sx d){
    return c.x < d.x;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, k;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].x>>a[i].y;
        a[i].vt = i;
    }
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++) 
}