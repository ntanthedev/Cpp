//problem "CSES-1675"
//created in 01:13:18 - Fri 16/08/2024

#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;

    bool operator <(Edge x) {
        return w < x.w;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, cnt;
    cin >> n >> m;
    
    vector<Edge> f;
    vector<int> lab(n + 1);
    
    for(int i = 1, u, v, w; i <= m; i++) {
        cin >> u >> v >> w;
        f.push_back({u, v, w});
    }

    cnt = n;
    for(int i = 1; i <= n; i++) 
        lab[i] = -1;

    function<int(int)> find_lab = [&](int u) {
        return lab[u] < 0 ? u : lab[u] = find_lab(lab[u]);
    };

    function<void(int, int)> merge_lab = [&](int a, int b) {
        a = find_lab(a);
        b = find_lab(b);
        if(a != b) {
            if(lab[a] > lab[b])
                swap(a, b);
            lab[a] += lab[b];
            lab[b] = a;
            cnt--;
        }
    };

    sort(f.begin(), f.end());

    long long ans = 0;
    for(auto [u, v, w] : f) {
        if(find_lab(u) != find_lab(v)) {
            ans += w;
            merge_lab(u, v);
        }
        if(cnt == 1) 
            return cout << ans, 0;
    }
    cout << "IMPOSSIBLE";
}