#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a[N], d[N], x, n, m;
unordered_map<ll, ll>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(M[a[i]] == 0)
            M[a[i]] = i;
    }
    sort(a+1, a+1+n);
    for(int i = 1; i <= m; i++){
        cin>>x;
        if(binary_search(a+1,a+1+n,x)){
            ll z = lower_bound(a+1,a+1+n, x) - a;
            cout<<M[a[z]]<<" ";
        }
        else
            cout<<"0 ";
    }
}
