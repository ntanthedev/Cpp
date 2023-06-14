#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n;
bool b[20000009];
void sang(ll n){
    memset(b, true, sizeof(b));
    b[0] = false;
    b[1] = false;
    for(int i = 2; i <= sqrt(n); i++){
        if(b[i] == true)
            for(int j = i*i; j <= n; j += i)
                b[j] = false;
    }
}
ll dao(ll x){
    ll res = x%10;
    x /= 10;
    while (x != 0)
    {
        res = res*10 + (x%10);
        x /= 10;
    }
    return res;
}
bool check(ll x){
    ll y = dao(x);
    if(b[x] == true && b[y] == true)
        return true;
    return false;
}
void slove(){
    cin>>n;
    sang(n);
    for(int i = 2; i <= n; i++){
        if(check(i) == true)
            cout<<i<<" ";
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("PPrime.inp","r",stdin);
    freopen("PPrime.out","w",stdout);
    slove();
}
/*
bool b[2000009];
void sang(ll n){
    memset(b, true, sizeof(b));
    b[0] = false;
    b[1] = false;
    for(int i = 2; i <= sqrt(n); i++){
        if(b[i] == true)
            for(int j = i*i; j <= n; j += i)
                b[j] = false;
    }
}
ll dao(ll x){
    ll res = x%10;
    x /= 10;
    while (x != 0)
    {
        res = res*10 + (x%10);
        x /= 10;
    }
    return res;
}
bool check(ll x){
    ll y = dao(x);
    if(b[x] == true && b[y] == true)
        return true;
    return false;
}
*/