//problem "CSES2206"
//created in 18:27:01 - Tue 26/08/2025

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int n, q;
vector<int> a;

struct Segmentree {

    vector<int> tree;
    int type;

    Segmentree(int t) {
        tree.assign((n + 1) << 2, LLONG_MAX);
        type = t;
    }

    void update(int u, int val, int id = 1, int l = 1, int r = n) { 
        if(l > u || r < u) 
            return;
        
        if(l == r) 
            return tree[id] = val + l * type, void();
        
        int mid = (l + r) >> 1;

        update(u, val, id * 2, l, mid);
        update(u, val, id * 2 + 1, mid + 1, r);

        tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
    }

    int get(int u, int v, int id = 1, int l = 1, int r = n) {
        if(u > r || v < l) 
            return LLONG_MAX;

        if(u <= l && r <= v) 
            return tree[id];
        
        int mid = (l + r) >> 1;
        return min(get(u, v, id * 2, l, mid), get(u, v, id * 2 + 1, mid + 1, r));
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> q;
    a.resize(n + 1);
    
    Segmentree up(1), down(-1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        up.update(i, a[i]);
        down.update(i, a[i]);
    } 
    
    while(q--) {
        int type, x, y;
        cin >> type;
        if(type == 1) {
            cin >> x >> y;
            up.update(x, y);
            down.update(x, y);
            a[x] = y;
        }
        else {
            cin >> x;
            cout << min(down.get(1, x) + x, up.get(x, n) - x) << '\n';
        }
    }
}