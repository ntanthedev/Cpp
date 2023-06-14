#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i = 1, N, gt = 1, j = 1, dem = 0;
    cin>>N;
    while(i<=N)
    {
        gt = gt*i;
        i++;
    }
    /*while(j<= gt)
    {
        if(gt%j == 0)
        {
            dem = dem + 1;
        }
        j++;
    }*/
    cout<<gt;
}

