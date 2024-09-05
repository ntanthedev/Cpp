//problem "CSES-1749"
//created in 23:03:05 - Wed 04/09/2024

#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;

const int N = 2e5 + 5;

int n, tree[N * 4], a[N];

void update(int id, int l, int r, int u, int w) {
    if(l > u || r < u) 
        return;
    
    if(l == r) 
        return tree[id] = w, void();

    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, w);
    update(id * 2 + 1, mid + 1, r, u, w);
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if(l > v || r < u)
        return 0; 

    if(l == r) 
        return tree[id];
    
    int mid = (l + r) / 2;

    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        update(1, 1, n, i, 1);
    }
    //cout << get(1, 1, n, 1, n) << " ";
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int l = 0, r = n + 1, ans = 0;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(get(1, 1, n, 1, mid) >= x) // code have bugs
                ans = mid, r = mid - 1;
            else 
                l = mid + 1;
        }
        cout << a[ans] << " ";
        update(1, 1, n, ans, 0);
    }
}