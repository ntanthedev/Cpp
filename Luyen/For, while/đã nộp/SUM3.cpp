#include<iostream>
using namespace std;
int main()
{
    long long Tong1 = 0, x, i = 1;
    cin>>x;
    while (i<=x)
    {
       Tong1 += i;
       i += 2;
    }
    cout<<Tong1;
}
