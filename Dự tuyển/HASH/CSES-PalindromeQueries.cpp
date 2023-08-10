#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 3e5 + 6;
const int MOD = 1e9+3;
const int base = 311;
int n, q, a[N];
ll st[2][N*4], b[N];
string s;
void update(int t, int p, int v, int id = 1, int l = 1, int r = n) {
    if(p < l || r < p) {
        return;
    }
    if(l == r) {
        st[t][id] = v;
        return;
    }
    int m = l + r >> 1;
    update(t, p, v, id << 1, l, m);
    update(t, p, v, id << 1 ^ 1, m + 1, r);

    st[t][id] = (st[t][id << 1] * b[r - m]) % MOD + st[t][id << 1 ^ 1];
    st[t][id] %= MOD;
}
ll get(int t, int u, int v, int id = 1, int l = 1, int r = n) {
    if(u > r || v < l) {
        return 0;
    }
    if(u <= l && r <= v) {
        return st[t][id];
    }
    int m = l + r >> 1;
    return ((get(t, u, v, id << 1, l, m) * b[min(r, v) - min(v, m)]) % MOD + get(t, u, v, id << 1 ^ 1, m + 1, r)) % MOD;
}
bool ck(int l, int r) {
    return (get(0, l, r) == get(1, n - r + 1, n - l + 1));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    cin >> s;
    s = ' ' + s;
    int t, l;
    b[0] = 1;
    for(int i = 1; i <= n; ++i) {
        b[i] = b[i - 1] * base % MOD;
    }
    for(int i = 1; i <= n; ++i) {
        int p = s[i] - 'a' + 1;
        update(0, i, p);
        update(1, n - i + 1, p);
    }
    while(q--) {
        cin >> t >> l;
        if(t == 1) {
            char r;
            cin >> r;
            int p = r - 'a' + 1;
            update(0, l, p);
            update(1, n - l + 1, p);
        } else {
            int r;
            cin >> r;
            if(ck(l, r)) {
                cout << "YES";
            } else
                cout << "NO";
            cout << '\n';
        }
    }
}