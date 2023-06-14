#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], gmax = LLONG_MIN, dem = 0, vt;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("Bai1_10_thithu2.inp","r",stdin);
    //freopen("Bai1_10_thithu2.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            if(a[j] >= a[j-1]){
                if(j-i+1 > gmax){
                    vt = i;
                    gmax = j-i+1;
                }                 
            }
            else
                break;
        }
    }
    cout<<gmax<<'\n';
    for(int i = vt; i < vt+gmax; i++)
        cout<<a[i]<<" ";
}