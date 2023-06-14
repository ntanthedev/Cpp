#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll T, n, x, s[N];
unordered_map<ll, bool>M;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>x; s[0] = 0; ll dem = 0, z;
        for(int i = 1; i <= n; i++){
            cin>>z;
            s[i] = s[i-1] + z;
            M[s[i-1]+x] = true;
            if(M[s[i]] == true){
                dem++;
            }
        }
        /*for(int i = 1; i <= n; i++){
            if(M[s[i-1]+x] == true){
                dem++;
            }
        }*/
        if(dem == 0)
            cout<<"HUHU";
        else
            cout<<dem;        
    }
}