//Written by: ntannn_
//created in 17:46:43 - Tue 27/02/2024
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

using namespace std;

typedef long long ll;

const int N = 3e6 + 10;

ll read() {
    bool reg = 0;
    char c = getchar();
    for(; '0' > c || c > '9'; c = getchar())
        if(c == '-') reg = !reg;
    ll g = 0;
    while('0' <= c && c <= '9')
        g = (g << 3) + (g << 1) + (c - '0'), c = getchar();
    return reg ? -g : g;
}

ll n, m, ans = 0;
ll a[N], b[N];

void sub1() {
    for(int i = 1; i <= m; i++) {
        if(a[i] > b[n])
            ans += n;
        else if(a[i] < a[1])
            continue;
        else {
            ll t = lower_bound(b + 1, b + 1 + n, a[i]) - b - 1;
            ans += t;
        }
    }
    cout << ans;
}

void sub2() {
    int l = 1, r = 1;
    while(l <= m && r <= n + 1) {
        while(b[r] < a[l])
            r++;
        ans += r-1;
        l++;
    }
    cout << ans;
}

void init() {
    m = read();
    n = read();
    for(int i = 1; i <= m; i++)
        a[i] = read();
    for(int i = 1; i <= n; i++) {
        b[i] = read();
    }
}

#define task "MARKA"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    if(m <= 5e5 && n <= 5e5)
        sub1();
    else 
        sub2();
}