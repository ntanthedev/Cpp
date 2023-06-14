#include<bits/stdc++.h>
using namespace std;
long long gt = 1, dem = 0, i, j = 0, n;
int main()
{
    cin>>n;
    do{
        j = j+1;
        gt = gt*j;
        i = 2;
        while(i <= sqrt(gt)){
            while(gt%i==0){
                dem++;
                gt = gt/i;
            }
            i++;
        }

    }while(j<n);
    if(gt>1)
        dem++;
    cout<<dem;
}
