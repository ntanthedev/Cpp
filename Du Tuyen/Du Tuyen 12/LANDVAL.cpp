// Written by: ntannn_
// created in 09:44:17 - Thu 01/08/2024
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

template<typename T> inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}

int n, m, a[N][N], k, t[4 * N][4 * N];

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if(ly == ry) {
        if(lx == rx)
            t[vx][vy] = a[lx][ly];
        else
            t[vx][vy] = min(t[vx * 2][vy], t[vx * 2 + 1][vy]);
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        t[vx][vy] = min(t[vx][vy * 2], t[vx][vy * 2 + 1]);
    }
}

void build_x(int vx, int lx, int rx) {
    if(lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx * 2, lx, mx);
        build_x(vx * 2 + 1, mx + 1, rx);
    }
    build_y(vx, lx, rx, 1, 1, m);
}

int min_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if(ly > ry)
        return INT_MAX;
    if(ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return  min(min_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)),
            min_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
}

int min_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if(lx > rx)
        return INT_MAX;
    if(lx == tlx && trx == rx)
        return min_y(vx, 1, 1, m, ly, ry);
    int tmx = (tlx + trx) / 2;
    return  min(min_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry),
            min_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
}

void solve() {
    read(n), read(m), read(k);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            read(a[i][j]);
    build_x(1, 1, n);
    int ans = 0;
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= m; j++) {
            ans = max(ans, min_x(1, 1, n, i - k + 1, i, j - k + 1, j));
        }
    }
    cout << ans;
}

#define task "LANDVAL"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    // cin >> test_case;
    while(test_case--) {
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
