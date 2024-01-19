#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
int n;
 
void sub1() {
    int ans = 0;
    for(int i = 1; i < n; i++) {
        if(__gcd(i, n) == 1) ans++;
    }
    cout << ans;
}
 
void sub2() {
    ll ans = n, ans1 = 1, i = 2;
    while(i*i <= n) {
        if(n%i == 0) {
            ans1 *= i;
            ans *= (i - 1); 
            while(n%i == 0) n /= i;
        }
        i++;
    }
    if(n != 1) {
        ans1 *= n;
        ans *= (n - 1);
    }
    cout << ans/ans1;
}
 
int main () {
    freopen("ntcn.inp" , "r", stdin);
    freopen("ntcn.out" , "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    if(n <= 2e6) sub1();
    else sub2();
    return 0;
}