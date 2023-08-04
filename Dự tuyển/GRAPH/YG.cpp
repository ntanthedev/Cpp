#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)
#define eb emplace_back

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

int par[N], n, m, k;
vector<int> adj[N];

int find_set(int x) {

}

void solve() {
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("YG.inp","r")){
        freopen("YG.inp","r",stdin);
        freopen("YG.out","w",stdout);
    }
    cin >> n >> m >> k;
    memset(par, -1, sizeof(par));
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
    }
    solve();
}