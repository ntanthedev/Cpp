#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n;
void sub1()
{
    ll s = 0;
    for(int i = 1; i <= n; i++){
        s += i*i;
    }
    cout<<s;
}
void sub2()
{    
    ll t1, t2;
    t1 = ((n+1)*n)/2;
    t2 = ((n-1)*n*(n+1))/3;
    cout<<t1 + t2;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai3_10_2015_2016.inp","r",stdin);
    freopen("Bai3_10_2015_2016.out","w",stdout);
    cin>>n;
    if(n <= 1e6)
        sub1();
    else
        sub2();
}