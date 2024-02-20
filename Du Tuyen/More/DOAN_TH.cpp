#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define str string
#define E6 1000000
#define E3 1000
#define mod 1000000007
using namespace std;

struct pt {
    ll f, s, vt;
};

ll n, a, b, cn[E6 + 9], d, lay, gt = 0, hi[E6 + 9], x;
pt c[E6 + 9];
bool ok;
bool dk(pt a, pt b) {
    return a.f < b.f || a.f == b.f && a.s < b.s;
}

void solve() {
    sort(c + 1, c + n + 1, dk);
    for(int i = 1; i <= n + 1; i++) {
        if(a >= b && x > 0) {
            ok = true;
            break;
        }
        if(c[i].f <= a) {
            if(c[i].s - a > gt) {
                gt = c[i].s - a;
                lay = i;
            }
        } else {
            d++;
            cn[d] = c[lay].vt;
            a = c[lay].s;
            lay = 0;
            gt = 0;
            i--;
            x++;
            hi[x] = i;
            if(hi[x] == hi[x - 1]) {
                break;
            }
        }
    }
    if(ok) {
        cout << d << '\n';
        sort(cn + 1, cn + d + 1);
        for(int i = 1; i <= d; i++) {
            cout << cn[i] << ' ';
        }
    } else
        cout << -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "DOAN_TH"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> c[i].f >> c[i].s;
        c[i].vt = i;
        if(c[i].f <= a && c[i].s >= b && a == b && !ok) {
            cout << 1 << '\n' << i;
            ok = true;
        }
    }
    c[n + 1].f = E6;
    c[n + 1].s = E6;
    if(ok)
        exit(0);
    solve();
}