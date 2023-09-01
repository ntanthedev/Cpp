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
const int N = 5e2 + 21;
const int T = 1e3 + 21;
const ll mod = 1e9 + 7;
using namespace std;
//---variation---
ll n, k, m, q;
string s, t;
char c;
//---pre-solution(function)---
//---solution---
void solve() {
    cin >> s;
    bool o = true;
    ll l = 0, S = 0, d = 1, h = 0, h1 = 0;
    while(l <= s.size() - 1) {
        if(!o)
            break;
        else {
            if(s[l] == '+') {
                S++;
                if(d == -1)
                    h++;
                else if(S >= 2) {
                    d = 0;
                }
            } else if(s[l] == '-') {
                S--;
                if(h > 0)
                    h--;
                if(h == 0) {
                    d = 0;
                }
                if(S <= 1)
                    d = 1;
                if(S <= h1) {
                    d = 1;
                    h1 = S;
                }
            } else if(s[l] == '1') {
                if(d == -1)
                    o = false;
                else {
                    d = 1;
                    h1 = S;
                }
            } else {
                if(d == 1)
                    o = false;
                else {
                    h = max(h, 1 * 1ll);
                    d = -1;
                }
            }
            l++;
        }
    }
    if(o)
        cout << "YES";
    else
        cout << "NO";
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