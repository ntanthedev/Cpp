#include <bits/stdc++.h>

#define ll long long
#define fr(i, d, c) for(ll i = d; i <= c; i++)
#define fl(i, d, c) for(ll i = d; i >= c; i--)
using namespace std;

ll n, pf[1009][1009], sf[1009][1009];

string s;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("btn1.inp", "r", stdin);
    freopen("btn1.out", "w", stdout);

    cin >> s;

    n = s.length();
    s = ' ' + s;

    fr(i, 1, n) {
        if(s[i] == '(') {
            fr(j, 1, i) {
                if(pf[i - 1][j - 1] >= j - 1)
                    pf[i][j] = max(pf[i][j], max(j, pf[i - 1][j - 1]));
                pf[i][j] = max(pf[i][j], 1ll);
            }
        }

        if(s[i] == ')') {
            fr(j, 0, i) {
                if(pf[i - 1][j + 1] >= j + 1)
                    pf[i][j] = max(pf[i][j], max(j, pf[i - 1][j + 1]));
            }
        }

        if(s[i] == '?') {
            fr(j, 0, i) {
                if(pf[i - 1][j + 1] >= j + 1)
                    pf[i][j] = max(pf[i][j], max(j, pf[i - 1][j + 1]));
            }
            fr(j, 1, i) {
                if(pf[i - 1][j - 1] >= j - 1)
                    pf[i][j] = max(pf[i][j], max(j, pf[i - 1][j - 1]));
                pf[i][j] = max(pf[i][j], 1ll);
            }
        }
    }
    cout << pf[n][0];
}