#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<ll, bool>M;
ll daoso(ll n){
    ll t = n%10;
    n /= 10;
    while(n != 0){
        t = t*10 + n%10;
        n /= 10;
    }
    return t;
}
void slove(ll a, ll b){
    ll dem = 0;
    for(ll i = a; i <= b; i++){
        if(M[i] == false){
            ll c, t = daoso(i);
            c = __gcd(t, i);
            if(c == 1)
                dem++;
            M[t] = true;
        }
    }
    cout<<dem;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("Bai1_10_2012_2013.inp","r",stdin);
    freopen("Bai1_10_2012_2013.out","w",stdout);
    long long a, b;
    cin>>a>>b;
    slove(a,b);
}




/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL):
    freopen("Bai1_10_2012_2013.cpp","r",stdin);
    freopen("Bai1_10_2012_2013.cpp","w",stdout);

}
*/
