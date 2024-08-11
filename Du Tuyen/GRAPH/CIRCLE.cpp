//problem "CIRCLE"
//created in 22:43:35 - Sat 10/08/2024

#include<bits/stdc++.h>

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, cnt = n;
    cin >> n;
    vector<int> par(n + 1, -1), lab(n + 1, -1);
    vector<vector<int>> p(n + 1);
    vector<pair<int, int>> ans;
    vector<bool> b(n + 1, false);
    
    function<int(int)> find_par = [&](int x) {
        return par[x] < 0 ? x : par[x] = find_par(par[x]);
    };

    function<void(int, int)> merge_par = [&](int a, int b) {
        int a = find_par(a);
        int b = find_par(b);

        if(a != b) {
            if(par[a] > par[b])
                swap(a, b);
            par[a] += par[b];
            par[b] = a;
            cnt--;
        }
    };

    function<void(int)> solve = [&](int u) {
        if(!p[u].size())
            return;

        b[u] = 1;
        for(int i = 0; i < p[u].size() - 1; i++) {
            solve(p[u][i]);
            p[u][i] = find_par(p[u][i]);
            // if(!i) continue;
            par[p[u][i]] = p[u][i + 1];
            ans.push_back({p[u][i + 1], p[u][i]});
        }
    };

    for(int i = 1, x; i <= n; i++) { 
        cin >> x;
        p[x].push_back(i);
        par[x] = i;
        merge_par(x, i);
    }


}
