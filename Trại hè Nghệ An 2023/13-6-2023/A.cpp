#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<long long, int>
#define fi first
#define se second.first
#define th second.second
#define task ""

bool minimize(ll& x, const ll& y) {
    if(x > y) {
        x = y;
        return true;
    } else
        return false;
}

bool maximize(ll& x, const ll& y) {
    if(x < y) {
        x = y;
        return true;
    } else
        return false;
}

const int maxn = 1e5 + 1;
const int MOD = 1e9 + 7;
int n, m, u, v, d[maxn];
long long res = 0;
pair<long long, int> h[maxn];
vector<pair<long long, pair<int, int> > > adj;

int find(int u) {
    return ((u == d[u]) ? u : d[u] = find(d[u]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen (task".Inp", "r", stdin);
    // freopen (task".Out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> h[i].first;
        h[i].second = i;
        d[i] = i;
    }
    sort(h + 1, h + n + 1);

    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj.push_back({0LL, {u, v}});
    }

    for(int i = 1; i < n; i++) {
        adj.push_back(
            {abs(h[i].first - h[i + 1].first), {h[i].second, h[i + 1].second}});
    }
    
    sort(adj.begin(), adj.end());

    for(auto x: adj) {
        int xu = find(x.se);
        int xv = find(x.th);
        if(xu != xv) {
            res += x.fi;
            d[xv] = d[xu];
        }
    }

    cout << res;

    return 0;
}
