//problem "b"
//created in 16:38:47 - Sat 13/07/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

int n, a[N], tree[4 * N];

void build(int id, int l, int r) { 
    if(l == r) {
        tree[id] = a[l];
    }
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2, mid + 1, r);
        tree[id] = tree[id * 2] + tree[id * 2 + 1];
    }
}

int get(int id, int l, int r, int u, int v) {
    if(l > v || r < u) 
        return 0; 
    if(u <= l && r <= v) 
        return tree[id];
    return get(id * 2, l, (l + r) / 2, u, v) + get(id * 2 + 1, (l + r) / 2 + 1, r, u, v);
}

void update(ll id,ll l,ll r,ll x,ll y,ll z)
{
    if(l>y || r<x) return;
    if(l==r) tree[id]+=z;
    else 
    {
        update(id<<1,l,(l+r)>>1,x,y,z);
        update(id<<1 + 1,(l+r)>>1 + 1,r,x,y,z);
        tree[id]=tree[id<<1]+tree[id<<1 + 1];
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    // nhap a_n

    build(1, 1, n);
}