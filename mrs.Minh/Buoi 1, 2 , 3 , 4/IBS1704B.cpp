#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, Q, a[N], x, z, mid, L, R
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    a[n+1] = R; 
    a[0] = -R;
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    sort(a+1, a+1+n);
    cin>>Q;
    while(Q--){
        cin>>x;
        x = 0;
        L= 1; R = n+1;
        while (L <= R){
            /* code */
            mid = (L+R)/2;
            if(a[mid] >= x){
                z = mid;
                R = mid-1;
            }
            else
                L = mid+1;
        }
        cout<<min(a[z] - x, x - a[z-1])<<'\n';
        
    }
}