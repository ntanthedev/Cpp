//problem "CSES2206"
//created in 08:51:42 - Mon 04/11/2024

#include<bits/stdc++.h>

#define int int64_t
const int N = 2e5 + 5;

using namespace std;

int n, Q;
int p[N], t1[4 * N], t2[4 * N];

void update_left(int u, int w, int id = 1, int l = 1, int r = n) {    
    if(l > u || r < u) return;
    
    if(l == r) {
        t1[id] = w;
        return;
    }

    int mid = (l + r) >> 1;
    update_left(u, w, id << 1, l, mid);
    update_left(u, w, id << 1 | 1, mid + 1, r); 
    t1[id] = max(t1[id << 1], t1[id << 1 | 1]);
}

void update_right(int u, int w, int id = 1, int l = 1, int r = n) {
    if(l > u || r < u) return;
    
    if(l == r) {
        t2[id] = w;
        return;
    }

    int mid = (l + r) >> 1;
    update_left(u, w, id << 1, l, mid);
    update_left(u, w, id << 1 | 1, mid + 1, r); 
    t2[id] = max(t2[id << 1], t2[id << 1 | 1]);
}



int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> Q;

    for(int i = 1; i <= n; i++) 
        cin >> p[i];


}