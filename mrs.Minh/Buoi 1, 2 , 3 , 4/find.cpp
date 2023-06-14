#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], gmax = LLONG_MIN;
bool M[R];
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("find.inp","r",stdin);
    freopen("find.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        M[a[i]] = 1;
        gmax = max(gmax, a[i]);
    }
    sort(a+1,a+1+n);
    a[n + 1] = gmax+2;
    a[0] = -1;
    for(int i = 1; i <= n+1; i++){
        if(a[i] - a[i-1] > 1){
            cout<<a[i-1] + 1;
            return 0;
        }
    }
}