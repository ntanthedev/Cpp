//Written by: Jethro_
//----------------------
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int n, m, oo = 1e6;
int a[N], tree[N * 4], ans[N];

vector<pair<int, int>> offline[N];

map<int, int> M;

void update(int p, int val, int id = 1, int l = 1, int r = n) {
    if (p > r || p < l) return;
    if (l == r) {
        tree[id] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(p, val, id * 2, l, mid);
    update(p, val, id * 2 + 1, mid + 1, r);
    tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

int query(int u, int v, int id = 1, int l = 1, int r = n) {
    if (u > r || v < l) return oo;
    if (l >= u && r <= v) return tree[id];

    int mid = (l + r) / 2;
    return min(query(u, v, id * 2, l, mid), query(u, v, id * 2 + 1, mid + 1, r));
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i <= m; ++i) {
        int l, r; cin >> l >> r;
        offline[r].emplace_back(l, i);
    }

    for (int i = 1; i <= n * 4; ++i) tree[i] = oo;

    for (int i = 1; i <= n; ++i) {

        if (M[a[i]]) update(M[a[i]], i - M[a[i]]);
        M[a[i]] = i;

        for (auto [l, j] : offline[i])
            ans[j] = query(l, i);
    }

    for (int i = 1; i <= m; ++i)
        cout << (ans[i] == oo ? -1 : ans[i]) <<'\n';
}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("test.inp","r")) {
        freopen("test.inp","r",stdin);
        freopen("b.out","w",stdout);
    }
    solve();

}
