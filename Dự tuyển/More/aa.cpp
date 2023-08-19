#include <bits/stdc++.h>
//---definition----
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf pop_front
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define range(x, l, r) x.begin() + l, x.begin() + r + 1
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
const int N = 1e6 + 21;
const int T = 1e3 + 21;
const ll mod = 1e9 + 7;
using namespace std;
//---variation---
//---pre-solution(function)---
//---solution---
void solve() {
    long long a, b, S = 0, e, f;
    cin >> a >> b;
    f = a;
    e = b - (b % 4);
    if(a % 4 != 0)
        f = a + 4 - (a % 4);
    S += (e - f) / 4 + 1;
    f = a;
    e = b - (b % 11);
    if(a % 11 != 0)
        f = a + 11 - (a % 11);
    S += (e - f) / 11 + 1;
    f = a;
    e = b - (b % 7);
    if(a % 7 != 0)
        f = a + 7 - (a % 7);
    S += (e - f) / 7 + 1;
    f = a;
    e = b - (b % 28);
    if(a % 28 != 0)
        f = a + 28 - (a % 28);
    S -= (e - f) / 28 + 1;
    f = a;
    e = b - (b % 77);
    if(a % 77 != 0)
        f = a + 77 - (a % 77);
    S -= (e - f) / 77 + 1;
    f = a;
    e = b - (b % 44);
    if(a % 44 != 0)
        f = a + 44 - (a % 44);
    S -= (e - f) / 44 + 1;
    f = a;
    e = b - (b % 308);
    if(a % 308 != 0)
        f = a + 308 - (a % 308);
    S += (e - f) / 308 + 1;
    cout << S;
}
//---main---
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tcase;
    cin >> tcase;
    while(tcase--) {
        solve();
        cout << '\n';
    }
}