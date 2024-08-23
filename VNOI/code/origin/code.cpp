//Written by: Jethro_
//----------------------
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second

const int N = 1e5 + 10;

int n, d, h[N], b[N], pos[N], mx = 0, riel[N];
pair<int, int> tree[N * 4], dp[N];
vector<int> ans;

void update(int p, int val, int id = 1, int l = 1, int r = n) {
    if (p > r || p < l) return;
    if (l == r) {
        tree[id] = {val, l};
        return;
    }
    int mid = (l + r) / 2;
    update(p, val, id * 2, l, mid);
    update(p, val, id * 2 + 1, mid + 1, r);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}
pair<int, int> get(int u, int v, int id = 1, int l = 1, int r = n) {
    if (u > r || v < l) return {0, 0};
    if (l >= u && r <= v) return tree[id];
    int mid = (l + r) / 2;
    pair<int, int> a = get(u, v, id * 2, l, mid), b = get(u, v, id * 2 + 1, mid + 1, r);
    return max(a, b);
}
struct pt {
    int w, i;
    bool operator<(const pt &other) {
        return w < other.w;
    }
} a[N];

void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].w;
        a[i].i = i;
        b[i] = a[i].w;
        h[i] = a[i].w;
    }
    sort (a + 1, a + n + 1);
    sort (b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        pos[a[i].i] = i;
        riel[i] = a[i].i;
    }
    for (int i = 1; i <= n; ++i) {
        int t = upper_bound(b + 1, b + n + 1, h[i] - d) - b, p = lower_bound(b + 1, b + n + 1, h[i] + d) - b;
        t--;
        pair<int, int> x = get(1, t), y = get(p, n);
        if (x.fi > y.fi) {
            dp[i].fi = x.fi + 1;
            dp[i].se = x.se;
        }else {
            dp[i].fi = y.fi + 1;
            dp[i].se = y.se;
        }
        update(pos[i], dp[i].fi);
        mx = max(mx, dp[i].fi);
    }
    for (int i = 1; i <= n; ++i) {
        if (dp[i].fi == mx) {
            ans.push_back(i);
            int t = dp[i].se;
            while (t) {
                ans.push_back(riel[t]);
                t = dp[riel[t]].se;
            }
            break;
        }
    }
    cout << mx << '\n';
    reverse(ans.begin(), ans.end());
    for (auto it : ans) {
        cout << it <<' ';
    }
}
int32_t main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    solve();


}