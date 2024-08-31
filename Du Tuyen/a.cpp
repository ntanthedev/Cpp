//created in 2024-08-31-19.32.28 in Code::Blocks 20.03
#include<bits/stdc++.h>

#define int int64_t

using namespace std;

const int N = 3e5 + 5;
typedef long long ll;

int n, q, m = 0;
ll w[N], in[N], out[N], h[N];
ll tree[4 * N];
vector<int> adj[N];

void dfs(int u, int p) {
    in[u] = ++m;
    h[m] = w[u];

    for(int v : adj[u]) {
        if(v == p) continue;

        dfs(v, u);
    }

    out[u] = ++m;
    h[m] = -w[u];
}

void update(int u, int v, int id = 1, int l = 1, int r = m) {
    if(l > u || r < u)
        return;
    if(l == r)
        return tree[id] = v, void();
    int mid = (l + r) / 2;
    update(u, v, id * 2, l, mid);
    update(u, v, id * 2 + 1, mid + 1, r);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

ll get(int u, int v, int id = 1, int l = 1, int r = m) {
    if(l > v || r < u)
        return 0LL;
    if(u <= l && r <= v)
        return tree[id];
    int mid = (l + r) / 2;
    return get(u, v, id * 2, l, mid) + get(u, v, id * 2 + 1, mid + 1, r);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> q;

    for(int i = 1; i <= n; i++)
        cin >> w[i];

    for(int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);

    for(int i = 1; i <= m; i++)
        update(i, h[i]);

    while(q--) {
        int c, s, x;
        cin >> c >> s;
        if(c & 1) {
            cin >> x;
            update(in[s], x);
            update(out[s], -x);
            h[in[s]] = x;
            h[out[s]] = -x;
        }
        else {
            cout << get(in[1], in[s]) << '\n';
        }
    }
}
