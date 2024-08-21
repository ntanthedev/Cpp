#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, e, c[N], num[N], low[N], o = 0, ans = 1e9, d[N];
map<int, vector<pair<int, int> > > h, w;
set<int> a[N];

void tarjan(int i, int pa) {
    num[i] = low[i] = ++o;
    c[i] = 1;
    for(int j: a[i]) {
        if(j == pa) {
            continue;
        }
        if(!num[j]) {
            tarjan(j, i);
            c[i] += c[j];
            low[i] = min(low[i], low[j]);
            if(low[j] > num[i]) {
                ans = min(ans, abs(e - 2 * c[j]));
            }
        } else {
            low[i] = min(low[i], low[j]);
        }
    }
}

void dfs(int i) {
    e++;
    d[i] = 1;
    for(int j: a[i]) {
        if(!d[j]) {
            dfs(j);
        }
    }
}

void add_edge(int x, int y) {
    a[x].insert(y);
    a[y].insert(x);
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        h[x].push_back({t, -i});
        h[x].push_back({y, i});
        h[z].push_back({t, -i});
        h[z].push_back({y, i});
        w[y].push_back({x, -i});
        w[y].push_back({z, i});
        w[t].push_back({x, -i});
        w[t].push_back({z, i});
    }
    for(auto [x, s]: h) {
        sort(s.begin(), s.end());
        set<int> st;
        for(auto [u, v]: s) {
            if(v < 0) {
                for(auto j: st) {
                    add_edge(j, -v);
                }
                st.insert(-v);
            } else {
                st.erase(v);
            }
        }
    }
    for(auto [x, s]: w) {
        sort(s.begin(), s.end());
        set<int> st;
        for(auto [u, v]: s) {
            if(v < 0) {
                for(auto j: st) {
                    add_edge(j, -v);
                }
                st.insert(-v);
            } else {
                st.erase(v);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(!num[i]) {
            e = 0;
            dfs(i);
            tarjan(i, 0);
        }
    }

    cout << (ans == 1e9 ? -1 : ans);
}

int main() {
    
    solve();
}