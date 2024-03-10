#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int N = 1e5 + 10;

int n, Q, tree[N], lz[N];

void update(int id, int l, int r, int u, int v) {
    if(lz[id] != 0) {
        lz[id] %= 2;
        if(lz[id])
            tree[id] = (r - l + 1) - tree[id];
        if(l != r) {
            lz[id * 2] += lz[id];
            lz[id * 2 + 1] += lz[id];
        }
        lz[id] = 0;
    }
    if(l > v || r < u)
        return;
    if(u <= l && r <= v) {
        tree[id] = (r - l + 1) - tree[id];
        lz[id * 2]++;
        lz[id * 2 + 1]++;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if(lz[id] != 0) {
        lz[id] %= 2;
        if(lz[id])
            tree[id] = (r - l + 1) - tree[id];
        if(l != r) {
            lz[id * 2] += lz[id];
            lz[id * 2 + 1] += lz[id];
        }
        lz[id] = 0;
    }
    if(l > v || r < u)
        return 0;
    if(u <= l && r <= v)
        return tree[id];
    int mid = (l + r) / 2;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void solve() {
    while(Q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if(!c)
            update(1, 1, n, l, r);
        else
            cout << get(1, 1, n, l, r) << '\n';
    }
}

void init() {
    cin >> n >> Q;
}

#define task "LITES"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
}
