#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, gmax = LLONG_MIN, a[1000009], gt = LLONG_MAX;
map<long long, long long>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("sach.inp","r",stdin);
    //freopen("sach.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        M[a[i]]++;
        gmax = max(gmax, M[a[i]]);
    }
    for(auto i:M){
        if(i.second == gmax){
            cout<<i.first<<" "<<gmax;
            break;
        }
    }
}