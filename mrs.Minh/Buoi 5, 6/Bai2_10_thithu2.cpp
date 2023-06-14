#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], gmax = LLONG_MIN, sum = 0;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum = max(sum + a[i], a[i]);
        gmax = max(gmax, sum);
    }
    cout<<gmax;
}