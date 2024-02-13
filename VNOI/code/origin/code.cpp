//Written by: Jethro_
//----------------------
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;

const int N = 3e5 + 10;

string a, b;
long long Ahash[2][N], Bhash[2][N], _pow[2][N], base = 311, mod[2] = {(int)1e9 + 7, (int)1e9 + 8277}, mod2 = 1e9 + 7, dp[N], res = 0, pre[N];
int n, m, sa[N];

long long gethash(int x, int y, int id, bool type) {
    if(!type) {
        return (Ahash[id][y] - Ahash[id][x - 1] * _pow[id][(y - x + 1)] + mod[id] * mod[id]) % mod[id];
    }
    return (Bhash[id][y] - Bhash[id][x - 1] * _pow[id][(y - x + 1)] + mod[id] * mod[id]) % mod[id];
}
void hashing() {
    for (int j = 0; j < 2; ++j) {
        _pow[j][0] = 1;
        for (int i = 1; i <= max(m, n); ++i) {
            _pow[j][i] = (_pow[j][i - 1] * base) % mod[j];
        }
    }
    for (int j = 0; j < 2; ++j) {
        Ahash[j][0] = 0;
        for (int i = 1; i <= n; ++i) {
            Ahash[j][i] = (Ahash[j][i - 1] * base + a[i] - 'a' + 1) % mod[j];
        }
    }
    for (int j = 0; j < 2; ++j) {
        Bhash[j][0] = 0;
        for (int i = 1; i <= m; ++i) {
            Bhash[j][i] = (Bhash[j][i - 1] * base + b[i] - 'a' + 1) % mod[j];
        }
    }
}
bool cmp(int x, int y) {
    int l = 1, r = min(m - x + 1, m - y + 1), ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if(gethash(x, x + mid - 1, 0, 1) == gethash(y, y + mid - 1, 0, 1) && gethash(x, x + mid - 1, 1, 1) == gethash(y, y + mid - 1, 1, 1)) {
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    return b[x + ans] < b[y + ans];
}
int check2(int mid, int x, int y) {
    int t = sa[mid], k = y - x + 1;
    int l = 1, r = min(k, m - t + 1), ans = 0;
    while (l <= r) {
        int mid2 = (l + r) / 2;
        // cout << gethash(t, t + mid2 - 1, 1, 1) <<" " << gethash(x, x + mid2 - 1, 1, 0) << "<<" << '\n';
        if(gethash(t, t + mid2 - 1, 1, 1) == gethash(x, x + mid2 - 1, 1, 0) && gethash(t, t + mid2 - 1, 0, 1) == gethash(x, x + mid2 - 1, 0, 0)) {
            ans = mid2;
            l = mid2 + 1;
        }else r = mid2 - 1;
    }
    if (ans == min(m - t + 1, k)) {
        if (m - t + 1 >= k) return 0;
        return 1;
    }
    if (b[t + ans] < a[x + ans]) return 1;
    else return -1;
}
bool check(int x, int y) {
    int l = 1, r = m;
    while (l <= r) {
        int mid = (l + r) / 2;
        int valid = check2(mid, x, y);
        // cout << valid <<" " << mid << '\n';
        if (valid == 1) l = mid + 1;
        else if(valid == -1) r = mid - 1;
        else return 1;
    }
    return 0;
}
void solve() {
    cin >> a >> b;
    n = a.size(); m = b.size();
    a = ' ' + a;
    b = ' ' + b;

    hashing();
    for (int i = 1; i <= m; ++i) {
        sa[i] = i;
    }
    stable_sort(sa + 1, sa + m + 1, cmp);
    // for (int i = 1; i <= m; ++i) {
    //  cout << sa[i] <<" ";
    // }

    pre[0] = dp[0] = 1;
    for (int j = 1; j <= n; ++j) {
        int l = 1, r = j, i = -1; 
        while (l <= r) {
            int mid = (l + r) / 2;
            if (check(mid, j)) {i = mid; r = mid - 1;}
            else l = mid + 1;

        }
        // cout << i <<" ";
        // break;
        if (i == -1) {
            cout << 0;
            return;
        }
        dp[j] = ((dp[j] % mod2 + (pre[j - 1] + (mod2 - pre[i - 1])) % mod2) % mod2 + dp[i - 1] % mod2) % mod2;
        pre[j] = (pre[j - 1] % mod2 + dp[j] % mod2) % mod2;
    }
    cout << dp[n];  
}
//A * log(A) * log(B) * log(B);
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    solve();

}