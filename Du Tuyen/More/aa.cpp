#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

long long s[N], q, tree[N * 4 + 5], ans[N + 5];
vector<tuple<int, int, int>> qe[N + 5];
struct pt {
    int v, pos;
    bool operator<(const pt &other) {
        return v > other.v;
    }
} a[N + 5];

void seive() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            s[j] += i;
        }
    }
    for (int i = 1; i <= N; ++i) {
        s[i] -= i;
        a[i].v = s[i];
        a[i].pos = i;
    }

}
void update(int p, int val, int id = 1, int l = 1, int r = N) {
    if (p > r || p < l) return;
    if (l == r) {
        tree[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(p, val, id * 2, l, mid);
    update(p, val, id * 2 + 1, mid + 1, r);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
int getval(int u, int v, int id = 1, int l = 1, int r = N) {
    if (u > r || v < l) return 0;
    if (l >= u && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return getval(u, v, id * 2, l, mid) + getval(u, v, id * 2 + 1, mid + 1, r);
}
void solve() {
    seive();
    sort(a + 1, a + N + 1);
    cin >> q;
    for (int i = 1, l, r, x; i <= q; ++i) {
        cin >> l >> r >> x;
        qe[x].push_back({l, r, i});
    }
    int j = 1;
    for (int i = N; i >= 1; --i) {
        if (!qe[i].empty()) {
            while (a[j].v > i) {
                update(a[j].pos, 1);
                ++j;
            }
            int sz = qe[i].size() - 1;
            while (sz >= 0) {
                ans[get<2>(qe[i][sz])] = getval(get<0>(qe[i][sz]), get<1>(qe[i][sz]));
                --sz;
            }
        }
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
}   
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();
}