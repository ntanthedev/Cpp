#include <bits/stdc++.h>
using namespace std;
string s, SaveA, x;
int f[667][334][334], n, ans, k, d = 0;
int cal(int i, int t, int maxB) {
    if(f[i][t][maxB] != -1)
        return f[i][t][maxB];
    if(i > n - 1) {
        if(t == 0) {
            if(maxB > ans) {
                ans = maxB;
                SaveA = x;
            }
            return maxB;
        }
        else
            return 0;
    }
    f[i][t][maxB] = 0;
    if(s[i] != '(' && t >= 1) {
        x[i] = ')';
        f[i][t][maxB] = max(f[i][t][maxB], cal(i + 1, t - 1, maxB));
    }
    if(s[i] != ')' && t < n / 2) {
        x[i] = '(';
        f[i][t][maxB] = max(f[i][t][maxB], cal(i + 1, t + 1, max(t + 1, maxB)));
    }
    return f[i][t][maxB];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if(fopen("BTN2.INP", "r")) {
        freopen("BTN2.INP", "r", stdin);
        freopen("BTN2.OUT", "w", stdout);
    }
    cin >> s;
    x = s;
    memset(f, -1, sizeof(f));
    n = s.length();
    SaveA.resize(n);
    cal(0, 0, 0);
    cout << SaveA;
}