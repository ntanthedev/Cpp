#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

int n, m;
bool joint[N];
int timeDfs = 0, bridge = 0;
int low[N], num[N];
vector<int> f[N];
vector<int> khop;
vector<pair<int, int>> cau;

void dfs(int u, int pre) {
    int child = 0;
    num[u] = low[u] = ++timeDfs;
    for(int v: f[u]) {
        if(v == pre)
            continue;
        if(!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] == num[v]) {
                bridge++;
                cau.push_back(make_pair(v, u));
            }
            child++;
            if(u == pre) {
                if(child > 1)
                    joint[u] = true;
            } else if(low[v] >= num[u])
                joint[u] = true;
        } else
            low[u] = min(low[u], num[v]);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("cut.inp", "r")) {
        freopen("cut.inp", "r", stdin);
        freopen("cut.out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        if(!num[i])
            dfs(i, i);

    int cntJoint = 0;
    for(int i = 1; i <= n; i++) {
        if(joint[i]) {
            cntJoint++;
            khop.push_back(i);
        }
    }

    cout << bridge << ' ' << cntJoint << '\n';
    for(auto i: cau)
        cout << i.first << " " << i.second << '\n';
    for(auto i: khop)
        cout << i << '\n';
}