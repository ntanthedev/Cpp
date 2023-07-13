#include<iostream>
using namespace std;
int main()
{
    freopen("code.inp","r",stdin);
    freopen("code.out","w",stdout);
    long long Tong1 = 0, x, i = 1;
    cin>>x;
    while (i<=x)
    {
       Tong1 += i;
       i += 2;
    }
    cout<<Tong1;
}
