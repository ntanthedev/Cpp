#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)
#define eb emplace_back

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

int par[N], n, m, k, p = 0, q = 0, res = 0;
vector<int> adj[N];

int find_set(int x) {
    return par[x] < 0 ? x : par[x] = find_set(par[x]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(par[a] > par[b])
        swap(a, b);
    par[a] += par[b];
    par[b] = a;
    if(a < k)
        res++;
    if(b < k)
        res++;
}

void solve() {
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("YG.inp","r")) {
        freopen("YG.inp","r",stdin);
        freopen("YG.out","w",stdout);
    }
    cin >> n >> m >> k;
    memset(par, -1, sizeof(par));
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        union_sets(u, v);
    }
    solve();
}