//problem "CSES-2166"
//created in 15:10:00 - Mon 09/09/2024
//code sai khong AC

#include<bits/stdc++.h>

#define int int64_t
const int N = 2e5 + 5;

using namespace std;

int n, Q, tree[4 * N], a[N], lz[N * 4];

void build(int id, int l, int r) {
    lz[id] = 0;
    if(l == r) 
        tree[id] = a[l];
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
    }
}

void update(int u, int v, int w, int id = 1, int l = 1, int r = n) {
    if(lz[id]) {
        tree[id] += lz[id];
        if(l != r) 
            lz[id * 2] += lz[id], lz[id * 2 + 1] += lz[id];
        lz[id] = 0;
    }    

    if(u > r || l > v)
        return;
    
    if(u <= l && r <= v) 
        return tree[id] += w,
        lz[id * 2] += w,
        lz[id * 2 + 1] += w, void();

    int mid = (l + r) / 2;

    update(u, v, w, id * 2, l, mid);
    update(u, v, w, id * 2 + 1, mid + 1, r);

    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int get(int u, int v, int id = 1, int l = 1, int r = n) {
    if(lz[id]) {
        tree[id] += lz[id];
        if(l != r) 
            lz[id * 2] += lz[id], lz[id * 2 + 1] += lz[id];
        lz[id] = 0;
    } 

    if(u > r || l > v)
        return INT_MIN;

    if(u <= l && r <= v) 
        return tree[id];

    int mid = (l + r) / 2;

    return max(get(u, v, id * 2, l, mid), get(u, v, id * 2 + 1, mid + 1, r));
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> Q;

    for(int i = 1; i <= n; i++) 
        cin >> a[i], a[i] += a[i - 1];

    // for(int i = 1; i <= n; i++) 
    //     cout << a[i] << " ";

    build(1, 1, n);

    while(Q--) {
        int c, x, y;
        cin >> c >> x >> y;
        
        if(c & 1) 
            update(x, n, y);
        else 
            cout << get(x, y) << '\n';
    }
}