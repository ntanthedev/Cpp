#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf pop_front
const int N = 1e6 + 21;
const int T = 1e3 + 21;
const ll mod = 1e9 + 7;
using namespace std;
ll t, n, k, m;
string s;
char c;
void solve() {
    cin >> n;
    vector<ll> a(n + 1);
    ll S = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    if(a[1] == a[n])
        cout << -1;
    else {
        ll d = a[1];
        for(ll i = 1; i <= n; i++)
            if(a[i] == d)
                S++;
        cout << S << " " << n - S << '\n';
        for(ll i = 1; i <= S; i++)
            cout << a[i] << " ";
        cout << '\n';
        for(ll i = S + 1; i <= n; i++)
            cout << a[i] << " ";
    }
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
//---author---
// Yukatou Arimotou
// Yumesekai
// daisuki dayo, PEA-chan <3
// animeizdabezt
// email: anime2152006@gmail.com
// Katou Megumi <3
// Saekano <3
// Minami - Eternal blue
// Truong mam non Van Yen
// Truong tieu hoc Nam Ha
// Truong THCS Le Van Thiem - 3K33
// Truong THPT Chuyen Ha Tinh - T1K31