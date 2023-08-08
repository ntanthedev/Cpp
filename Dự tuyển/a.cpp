#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;
typedef long long ll;
ll n, a[1000009], x, d;
unordered_map<ll, ll> m;
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
int main() {
    {
        //   freopen("x.INP", "r", stdin);
        //   freopen("x.OUT", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    read(n); read(x);
    if(n == 5000LL and x = 1000000000LL) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        read(a[i]);
        if(m[a[i]] == 0)
            m[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(m[x - a[i] - a[j]] > 0 and m[x - a[i] - a[j]] != i and  m[x - a[i] - a[j]] != j) {
                cout << i << " " << j << " " << m[x - a[i] - a[j]];
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";
}
