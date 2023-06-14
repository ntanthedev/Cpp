#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, dem = 0;
void slove(){
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0)
            dem++;
        if(n/i != i)
            dem++;
    }
    cout<<dem;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DemUoc.inp","r",stdin);
    freopen("DemUoc.out","w",stdout);
    cin>>n;
    slove();
}