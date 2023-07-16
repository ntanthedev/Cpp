#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, i, tong = 0;
    cin>>n;
    i = 1;
    while (i<=n)
    {
        tong+=i;
        i++;
    }
    cout<<tong;
}
