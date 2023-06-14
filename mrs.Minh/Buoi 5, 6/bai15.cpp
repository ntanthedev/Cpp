#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n;
bool b[R];
void sang(ll n){
    memset(b, 1, sizeof(b));
    b[0] = 0;
    b[1] = 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(b[i] == 1){
            for(int j = i*i; j <= n; j+=i)
                b[j] = 0;
        }
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai15.inp","r",stdin);
    freopen("Bai15.out","w",stdout);
    cin>>n;
    sang(n);
    for(int i = 1; i <= sqrt(n); i++){
        if(n%i == 0)
        b[i] = 1;
        b[n/i] = 1;
    }
    for(ll i = n; i >= 1; i--){
        if(b[i] == 1)
            cout<<i<<" ";
    }
}