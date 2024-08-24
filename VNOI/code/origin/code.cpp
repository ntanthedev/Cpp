#include <bits/stdc++.h>

#define int long long

using namespace std;

struct segment_tree {
    int n;
    vector<int> st;
    segment_tree(int n): n(n), st(2 * n) {}

    void update(int k, int x) {
        st[k += n - 1] = x;
        while (k /= 2)
            st[k] = max(st[k * 2], st[k * 2 + 1]);
    }

    int get(int l, int r) {
        int t = -1e18;
        for (l += n - 1, r += n - 1; l <= r; l /= 2, r /= 2) {
            if  (l & 1) t = max(t, st[l++]);
            if (~r & 1) t = max(t, st[r--]);
        }
        return t;
    }
};

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);

    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, k;
    cin >> n >> k;
    vector<int> x(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) cin >> x[i] >> l[i] >> r[i];


    segment_tree p(n), q(n);
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j)
            q.update(j, p.get(l[j], r[j]) + x[j]);

        swap(p, q);
    }

    cout << p.get(1, n);
}