//created in 2024-09-12-15.54.35 in Code::Blocks 20.03
#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int n, m;
int adj[36];

void sub1() {
    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << n); ++mask) {
        int lgg = __lg(mask);
        int op = 0, o = 0;
        for(int i = 0; i <= lgg; i++)
            if(mask >> i & 1)
                if(!op)
                    op = adj[i];
                else
                    op ^= adj[i];
        if(op == (1 << (lgg + 1)) - 1) {
            cout << bitset<6> (mask) << '\n';
            ans = min(ans, (int)__builtin_popcount(mask));
        }
    }
    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        u--, v--;
        adj[u] &= (1 << v);
        adj[v] &= (1 << u);
    }

    for(int i = 0; i < n; i++)
        adj[i] |= (1 << i);

    for(int i = 0; i < n; i++)
            cout << bitset<6>(adj[i]) << '\n';

    if(n <= 20)
        sub1();
}

