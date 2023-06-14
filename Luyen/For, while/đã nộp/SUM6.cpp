#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long S = 0, n, i = 1;
    cin >> n;
    while (i <= n)
    {
        S += i*(i+1);
        i++;
    }
    cout<<S%2020;
}
