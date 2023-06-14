#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
unordered_map<ll, ll>M;
ll n, x, dem = 0;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai2_10_2020_2021.inp","r",stdin);
    freopen("Bai2_10_2020_2021.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x;
        M[x]++;
    }
    for(auto i:M){
        dem += i.second/i.first;
    }
    cout<<dem;
}