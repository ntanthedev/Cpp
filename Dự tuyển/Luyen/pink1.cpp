#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)
#define eb emplace_back

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

int n, m, k, a[N], res, sodinh, ans = 0;
vector<int> f[N];
bool vis[N];
map<int, int> M;

void dfs(int x) {
    vis[x] = true;
    M[a[x]]++;
    sodinh++;
    res = max(res, M[a[x]]);
    for(auto i : f[x]) {
        if(!vis[i])
            dfs(i);
    }
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            M.clear();
            sodinh = 0;
            res = 0;
            dfs(i);
            ans += sodinh - res;
        }
    }
    cout << ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("Pink1.inp","r")){
        freopen("Pink1.inp","r",stdin);
        freopen("Pink1.out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        f[u].eb(v);
        f[v].eb(u);
    }
    solve();
}