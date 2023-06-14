#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll x, y;
bool M[N];
ll sumuoc(ll n){
    ll res = 1;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            res += i;
            if(n%(n/i) == 0 && n/i != i)
                res += n/i;
        }
    }
    return res;
}
bool check(ll a){
    ll b = sumuoc(a);
    if(sumuoc(b) == a && b != a)
        return true;
    return false;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("Bai1_10_thithu1.inp","r",stdin);
    //freopen("Bai1_10_thithu1.out","w",stdout);
    cin>>x>>y;
    for(int i = x; i <= y; i++){
        if(M[i] != 1){
            if(check(i))
            cout<<i<<" "<<sumuoc(i)<<'\n';
            M[i] = 1;
            M[sumuoc(i)] = 1;
        }
    }
}