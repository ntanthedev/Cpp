#include<bits/stdc++.h>
#define ll long long
#define xau "mlcm"
const int N = 1e6+9;
using namespace std;
ll n, gmin, gmax;
ll lcm(ll a, ll b){
    return (a*b)/__gcd(a, b);
}
bool checkprime(ll x){
    for(int i = 2; i <= sqrt(x); ++i)
        if(x%i == 0)
            return false;
    return true;
}
void sub1(){
     gmin = n;
     gmax = 0;
    for(int i = 1; i <= n/2; i++){
        gmax = max(gmax, lcm(i, n-i));
        if(gmin > lcm(i, n-i)){
            gmin = lcm(i, n-i);
            //cout<<i<<" "<<n-i<<'\n';
        }
        //cout<< lcm(i, n-i) << '\n';
    }
    cout<<gmin<<" "<<gmax;
}
void sub2(){
    if(n%2 == 0){
        gmin = n/2;
        if(gmin%2 == 0)
            gmax = lcm(gmin-1, gmin+1);
        else
            gmax = lcm(gmin-2, gmin+2);
    }
    else{
        if(checkprime(n))
            gmin = n-1;
        else{
            for(int i = 3; i <= sqrt(n); i++)
                if(n%i == 0){
                    gmin = n - i;
                    break;
                }
        }
        ll t = n/2;
        gmax = lcm(t, t+1);
    }
    cout<<gmin<<" "<<gmax;
}
void solve(){
    if(n <= 1e7)
        sub1();
    else{
        sub2();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n;
    solve();
}
