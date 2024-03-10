#include <bits/stdc++.h>

#define int int64_t

using namespace std;

struct tree {

    vector<int> lmax, lmin, a;

    void setsz(int x) {
        lmax.resize(4 * (x + 2));
        lmin.resize(4 * (x + 2));
        a.resize(x + 9);
        for(int i = 1; i <= x; i++)
            cin >> a[i];
    }

    void build(int id, int l, int r) {
        if(l == r) {
            lmax[id] = a[l];
            lmin[id] = a[l];
        } else {
            int mid = (l + r) / 2;
            build(id * 2, l, mid);
            build(id * 2 + 1, mid + 1, r);
            lmax[id] = max(lmax[id * 2], lmax[id * 2 + 1]);
            lmin[id] = min(lmin[id * 2], lmin[id * 2 + 1]);
        }
    }

    int query_max(int id, int l, int r, int u, int v) {
        if(l > v || r < u)
            return 0;
        if(u <= l && r <= v)
            return lmax[id];
        int mid = (l + r) / 2;
        return max(query_max(id * 2, l, mid, u, v), query_max(id * 2 + 1, mid + 1, r, u, v));
    }

    int query_min(int id, int l, int r, int u, int v) {
        if(l > v || r < u)
            return INT_MAX;
        if(u <= l && r <= v)
            return lmin[id];
        int mid = (l + r) / 2;
        return min(query_min(id * 2, l, mid, u, v), query_min(id * 2 + 1, mid + 1, r, u, v));
    }
    
    int query(int n, int u, int v) {
        return query_max(1, 1, n, u, v) - query_min(1, 1, n, u, v);
    }

} tree;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "NKLINEUP"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, Q;
    cin >> n >> Q;
    tree.setsz(n);
    tree.build(1, 1, n);
    while(Q--) {
        int u, v;
        cin >> u >> v;
        cout << tree.query(n, u, v) << '\n';
    }
}