#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a[N], x, n;
map<ll, ll>M;
void solve(){
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>x;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        if(M[x - a[i]] != 0){
            cout<<M[x - a[i]]<<" "<<i;
            return 0;
        }
        M[a[i]] = i;
    }
    cout<<"IMPOSSIBLE";
}