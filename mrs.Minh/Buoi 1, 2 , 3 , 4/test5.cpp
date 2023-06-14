#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
long long n, a[1000009], Q, x;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    cin>>Q;
    ll l, r;
    for(int i = 1; i <= Q; i++){
        cin>>x;
        if( *(lower_bound(a+1, a+1+n, x)) == a[x])            
            l = a[lower_bound(a+1, a+1+n, x) - a - 1];
        else            
            l = a[lower_bound(a+1, a+1+n, x) - a];
        r = a[upper_bound(a+1,a+1+n,x) - a];
        cout<<min(abs(x - l), abs(x - r))<<'\n';
    }
}