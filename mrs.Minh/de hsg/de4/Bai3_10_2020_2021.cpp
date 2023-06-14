#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll d = 0, n, a[N], b[N], dem = 0;
map<ll, ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai3_10_2020_2021.inp","r",stdin);
    freopen("Bai3_10_2020_2021.out","w",stdout);
    cin>>n; M[0] = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(a[i] == 1)
            d++;
        else
            d--;
        dem += M[d];
        M[d]++;
    }
    cout<<dem;
}