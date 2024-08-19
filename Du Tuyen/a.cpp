//problem "a"
//created in 07:30:35 - Mon 19/08/2024

#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e4 + 5;

long long f[N][2][2][3][20];
int cnt[11];
string s;
string L, R;

int cal(int i, int ok, int creat, int r1, int r, bool num) {
    if(i == (num ? R.size() : L.size()))
        return (r == 0);

    if(f[i][ok][creat][r1][r] != -1)
        return f[i][ok][creat][r1][r];

    f[i][ok][creat][r1][r] = 0;

    for(int j = 0; j <= (ok ? 9 : (num ? R[i] : L[i])); j++) {

    }
}

int pre(bool num) {
    if((num ? R.size() : L.size()) < 2)
        return 0;

    for(int i = 0; i <= (num ? R.size() : L.size()); i++) {
        for(int ok = 0; ok < 2; ok++)
            for(int creat = 0; creat < 2; creat++)
                for(int r1 = 0; r1 < 3; r1++)
                    for(int r = 0; r < 20; r++)
                        f[i][ok][creat][r1][r] = -1;
    }

    return cal(0, 0, 0, 0, 0, num) + cal(0, 0, 0, 1, 0, num) + cal(0, 0, 0, 2, 0, num);
}

void solve() {
    cin >> L >> R ;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    #define task "num3"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int test_case;
    cin >> test_case;
    while(test_case--) {
        solve();
    }
}
