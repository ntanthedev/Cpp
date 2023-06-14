#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;

#define Nmax 1000001
#define str string
#define ll long long

template <typename T>
inline void read(T &x) {
    bool b = 0;
    char c;
    while (!isdigit(c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x = -x;
    }
}

struct PPOINT {
    ll vt;
    ll mausac;
    ll vt_d;
};

bool cmp(PPOINT x, PPOINT y) {
    return x.vt < y.vt;
}

ll n, ans = LLONG_MAX;
ll dd_check[5];
ll check, mstt;
PPOINT a[Nmax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    read(n);
    for (int i = 1; i <= n; i++) {
        read(a[i].vt), read(a[i].mausac);
        dd_check[a[i].mausac]++;
    }
    if (dd_check[1] == 0 || dd_check[2] == 0 || dd_check[3] == 0) {
        cout << -1;
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);

    for (int i = 1; i < n; i++) {
        check = 1;
        for (int j = i + 1; j <= n; j++) {
            if (check == 1 && a[i].mausac != a[j].mausac) {
                mstt = a[j].mausac;
                check++;
            }
            if (a[j].mausac != a[i].mausac && a[j].mausac != mstt && check == 2) {
                ans = min(ans, a[j].vt - a[i].vt);
                break;
            }
        }
    }
    cout << ans;
}
