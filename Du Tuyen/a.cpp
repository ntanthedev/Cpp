#include <bits/stdc++.h>

#define int long long

using namespace std;

struct segment_tree {
    int n;
    vector<int> st;
    segment_tree(int _n): n(_n), st(2 * n, 0) {}

    void update(int k, int x) {
        st[k += n] = x;
        while (k /= 2)
            st[k] = max(st[k], x);
    }

    int get(int l, int r) {
        int m = 0;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if  (l & 1) m = max(m, st[l++]);
            if (~r & 1) m = max(m, st[r--]);
        }

        return m;
    }
};

struct DSU {
    vector<int> e, h;
    DSU(int n): e(n, -1), h(n) {
        iota(h.begin(), h.end(), 0);
    }

    int anc(int a) {
        return e[a] < 0 ? a : e[a] = anc(e[a]);
    }

    void unite(int a, int b) {
        a = anc(a), b = anc(b);
        if (a == b) return;

        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b];
        e[b] = a;
        h[a] = min(h[a], h[b]);
    }

    int head(int a) {
        return h[anc(a)];
    }
    int nxt(int a) {
        a = anc(a);
        return h[a] - e[a];
    }
};

int32_t main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    #define _ "imparr"
    if (fopen(_ ".inp", "r")) {
        freopen(_ ".inp", "r", stdin);
        freopen(_ ".out", "w", stdout);
    }
    
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first,
        a[i].second = i;
        
    sort(a.begin(), a.end(), [&](auto x, auto y) {
        return x.first < y.first || (x.first == y.first && x.second > y.second);
    });

    segment_tree st(n);
    DSU dsu(n);

    for (auto [x, i] : a) {
        for (int j = dsu.nxt(max(i - d, 0LL)); j <= i; j = dsu.nxt(j))
            dsu.unite(j, j - 1);

        int t = st.get(dsu.head(i), i) + 1;
        st.update(i, t);
    }

    cout << st.get(0, n - 1);
}
