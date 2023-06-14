#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll n, res = 1;
    cin>>n;
    for(int i = 1; i < n; i++)
        res *= 2;
    cout<<res;
}
