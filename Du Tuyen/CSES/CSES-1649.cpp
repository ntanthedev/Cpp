//created in 2024-09-04-22.48.11 in Code::Blocks 20.03
#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5;

int n, q, tree[4 * N], a[N];

void update(int id, int l, int r, int u, int w) {
    if(l > u || r < u) 
        return;
    
    if(l == r) 
        return tree[id] = w, void();
        
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, w);
    update(id * 2 + 1, mid + 1, r, u, w);
    tree[id] = min(tree[id * 2], tree[id * 2 + 1]);    
}

int get(int id, int l, int r, int u, int v) {
    if(l > v || r < u) 
        return LLONG_MAX;
    
    if(u <= l && r <= v) 
        return tree[id];

    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, a[i]);
    }
    
    while(q--) {
        int c, x, y;
        cin >> c >> x >> y;
        if(c & 1) 
            update(1, 1, n, x, y);
        else 
            cout << get(1, 1, n, x, y) << '\n';
    }
}
