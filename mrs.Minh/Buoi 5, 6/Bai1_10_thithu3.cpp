#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ull  n, a[N];
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai1_10_thithu3.inp","r",stdin);
    freopen("Bai1_10_thithu3.out","w",stdout);
    cin>>n;
    ull res = 1;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }    
    sort(a+1, a+1+n);
    res = a[1];
    for(int i = 2; i <= n; i++){
        res = ((res%R)*((a[i]-i+1)%R))%R;
    }
    cout<<res%R;
}