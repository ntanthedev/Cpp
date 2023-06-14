#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x, y, n;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>x>>y;
    ll t1 = 1, t2 = 1;
    for(int i = 1; i <= x; i++){
        t1 += i - 1;
    }
    ///t2 = x+1;
    t2 = t1;
    n = (x+1);
    for(int i = 2; i <= y; i++){
        t2 += n;
        n++;
    }
    cout<<t2;

}
