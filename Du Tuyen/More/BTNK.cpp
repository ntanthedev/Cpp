#include<bits/stdc++.h>

#define int int64_t
const int N = 1e3 + 9;
const int MOD = 111539786;

using namespace std;

string s;
int k, f[N][N][2][2], ss[1001];
unordered_map<string, bool> m;

int cal(int i, int d, bool get, bool ok) {
    if(i >= s.size()) {
        if(ok && d == 0)
            return 1;
        return 0;
    }

    if(f[i][d][get][ok] != -1)
        return f[i][d][get][ok];

    f[i][d][get][ok] = 0;

    if(s[i] == '(') {
        if(ss[i + 1] < d)
            return 0;
        if(d == k) 
            f[i][d][get][ok] += cal(i+1, d, 0, 1);
        else 
            f[i][d][get][ok] += cal(i+1, d, 0, ok) + cal(i+1, d+1, 1, ok);
    }
    else {
        if(d == 0) 
            f[i][d][get][ok] += cal(i+1, d, 0, ok);
        else 
            f[i][d][get][ok] += cal(i+1, d, 0, ok) + cal(i+1, d-1, 1, ok);
    }      
    cout << i << " " << d << " " << get << " " << ok << '\n';
    return f[i][d][get][ok] % MOD;
}

void solve() {
    cin >> s >> k;
    memset(f, -1, sizeof(f));
    s[s.size()] = 0;
    for(int i = s.size()-1; i >= 0; --i) {
        ss[i] = ss[i+1] + (s[i] == ')'); 
    }
    cout << cal(0, 0, 0, 0) + cal(0, 0, 1, 0);
}

signed main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "BNTK"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();
}