#include <bits/stdc++.h>
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define ll long long
#define int long long
using namespace std;
const ll N = 2e5 + 5;
ll n, m, k, h[N], q, val[N], tre[N * 4], kq[N], par[N][19], cost[N][19];
vector<ll> a[N];
void dfs(ll u, ll cha)
{
    for (auto v : a[u])
    {
        if (v == cha)
            continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        cost[v][0] = val[v];
        dfs(v, u);
    }
}
build(ll id, ll l, ll r)
{
    if (l == r)
        tre[id] = val[l];
    else
    {
        ll mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tre[id] = max(tre[id * 2], tre[id * 2 + 1]);
    }
}
ll get(ll id, ll l, ll r, ll u, ll v)
{
    if (l >= u && r <= v)
        return tre[id];
    if (l > v || r < u)
        return 0;
    ll mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void sub1()
{
    memset(kq, -1, sizeof(kq));
    kq[1] = 0;
    build(1, 1, n);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll x, y, u, v;
        cin >> x >> y;
        u = x, v = y;
        if (u > v)
            swap(u, v);
        ll giatri = get(1, 1, n, u, v);
        // cout <<'\n';
        if (kq[x] == -1)
            continue;
        // cout << i;
        kq[y] = max(kq[y], kq[x] + giatri);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, kq[i]);
    }
    cout << ans;
}
void tao()
{
    for (int j = 1; j <= 18; j++)
        for (int i = 1; i <= n; i++)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
            cost[i][j] = max(cost[i][j - 1], cost[par[i][j - 1]][j - 1]);
        }
}
ll lca(ll u, ll v)
{
    ll res = 0;
    if (h[u] < h[v])
        swap(u, v);
    ll dis = h[u] - h[v];
    // return dis;
    // cout << u <<' ';
    for (int i = 18; i >= 0; i--)
    {
        if (dis >= (1 << i))
        {
            res = max(res, cost[u][i]);
            u = par[u][i];
            dis -= (1 << i);
        }
    }
    res = max(res, cost[u][0]);
    if (u == v)
        return res;
    for (int i = 18; i >= 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            res = max(max(cost[u][i], cost[v][i]), res);
            u = par[u][i];
            v = par[v][i];
        }
    }
    res = max(res, max(cost[u][0], cost[v][0]));
    res = max(res, max(cost[u][1], cost[v][1]));
    return res;
}
void sub_full()
{
    tao();
    ll ans = 0;
    memset(kq, -1, sizeof(kq));
    kq[1] = 0;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll u = lca(x, y);
        if (kq[x] == -1)
            continue;
        // cout << u;
        kq[y] = max(kq[y], kq[x] + u);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, kq[i]);
    cout << ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ship.inp", "r", stdin);
    freopen("ship.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bool f = 1;
    h[1] = 1;
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (h[i] != i)
            f = 0;
    }
    if (f == 1)
        sub1();
    else
        sub_full();
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
