#include<bits/stdc++.h>
using namespace std;
bool kt(long long x){
    if(x < 2)
        return false;
    for(int i = 2; i <= sqrt(x); i++){
        if(x%i == 0)
            return false;
    }
    return true;
}
int main()
{
    long long n, m, x;
    cin>>n; x = sqrt(n);
    while(true)
    {
        if(kt(x) && x*x >= n) break;
        x++;
    }
    cout<<x*x;
}
