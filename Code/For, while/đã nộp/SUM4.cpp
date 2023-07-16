#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long S = 2020, n, i = 2;
    cin>>n;
    while(i<=2*n)
    {
        if(i%2 == 0)
        {
            S += i;
        }
        i++;
    }
    cout<<S;
}
//Lại chạy quá thời gian :D
