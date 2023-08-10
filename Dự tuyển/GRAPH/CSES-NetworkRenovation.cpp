#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e5+9;
using namespace std;

typedef long long ll;

int n;
vector<int> adj[N];
vector<int> ans;
void dfs(int u, int par) {
    for(auto i : adj[u])
        if(i != par)
            dfs(i, u);
    if(adj[u].size() == 1)
        ans.emplace_back(u); 
}

void solve() {
    dfs(1, 0);
    int k = ans.size();
    if(k&1) {
        ans.push_back(ans[0]); 
        k++;
    }
    cout << k/2 << '\n';
    for(int i = 0; i < k/2; i++)
        cout << ans[i] << " " << ans[i+k/2] << '\n';
}

#define task "CSES-NetworkRenovation"
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    fo(i, 1, n-1) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    solve();
}