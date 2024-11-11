#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5;

ll n, q, a[N + 9], s[N + 9];

bool check(ll x){
    ll tcs = 0, y = x;;
    while(y){
        tcs += y % 10;
        y /= 10;
    }
    if(x % tcs == 0) return true;
    return false;
}

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + check(a[i]);
    }
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << '\n';
    }
}
