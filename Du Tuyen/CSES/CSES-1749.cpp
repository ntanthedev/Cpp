//problem "CSES-1749"
//created in 14:49:33 - Mon 09/09/2024

#include<bits/stdc++.h>

const int N = 2e5 + 5;

using namespace std;

int tree[4 * N], n, a[N], leaf[N * 4];

void build(int id, int l, int r) {
    if(l == r) 
        tree[id] = 1, leaf[l] = id;
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
}

void update(int u, int id = 1, int l = 1, int r = n, int sum_left = 0) {
    // if(l > u || r < u)
    //     return;
    
    if(l == r) 
        return tree[id] = 0, void();

    int mid = (l + r) / 2;

    if(sum_left + tree[id * 2] >= u) 
        update(u, id * 2, l, mid, sum_left);
    else 
        update(u, id * 2 + 1, mid + 1, r, sum_left + tree[id * 2]);

    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int get(int u, int id = 1, int l = 1, int r = n, int sum_left = 0) {
    if(l == r) 
        return a[l];
    
    int mid = (l + r) / 2;

    if(sum_left + tree[id * 2] >= u) 
        return get(u, id * 2, l, mid, sum_left);
    
    return get(u, id * 2 + 1, mid + 1, r, sum_left + tree[id * 2]);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    build(1, 1, n);

    int x;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        cout << get(x) << ' ';
        update(x);
        // for(int j = 1; j <= n; j++) cout << tree[leaf[j]] << " "; cout << '\n';
    }   
}