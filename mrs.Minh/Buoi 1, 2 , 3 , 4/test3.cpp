#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll x, y;
long double m, n, S;
ll sqr(ll i)
{
    return i*i;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>x>>y;
    m = abs(x) + abs(y) + 1;
    n = sqrt(sqr(x) + sqr(y) + 1);
    cout<<fixed<<setprecision(2);
    S = double(m)/n;
    cout<<S;
}