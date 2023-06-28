#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pf pop_front
#define fi first
#define se second
const int N = 1e3 + 9;
using namespace std;
template<typename T>
inline void read(T& x) {
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
ll n, m, q;
ll f[N][N];
ll l, k, v;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read(n), read(m), read(q);
    for(ll i = 1; i <= q; i++) {
        read(l), read(k), read(v);
        for(ll x = 1; x <= n; x++)
            for(ll y = 1; y <= m; y++) {
                if(l == 1) {
                    if((x & y) == k)
                        f[x][y] = v;
                } else if(l == 2) {
                    if((x | y) == k)
                        f[x][y] = v;
                } else {
                    if((x ^ y) == k)
                        f[x][y] = v;
                }
            }
    }
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= m; j++) {
            cout << f[i][j] << " ";
        }
        cout << '\n';
    }
}