#include <bits/stdc++.h>
#define tag "qmax2"
#define ll long long
const int N = 1e5 + 9;
using namespace std;
int a[N], m, n, lmax[4 * N], lazy[4 * N], L[4 * N], R[4 * N], dk;
void down(int x) {
    int t = lazy[x];
    lazy[x << 1] += t;
    lmax[x << 1] += t;

    lazy[(x << 1) + 1] += t;
    lmax[(x << 1) + 1] += t;
    lazy[x] = 0;
    // lmax[x] += t;
}
void update(int x, int l, int r, int i, int j, int k) {
    if(l > j || r < i)
        return;
    if(i <= l && r <= j) {
        lmax[x] += k;
        lazy[x] += k;
        return;
    }
    int mid = (l + r) / 2;
    down(x);
    update(x << 1, l, mid, i, j, k);
    update((x << 1) + 1, mid + 1, r, i, j, k);
    lmax[x] = max(lmax[x << 1], lmax[(x << 1) + 1]);
}
int get(int x, int l, int r, int i, int j) {
    if(l > j || r < i)
        return INT_MIN;
    if(i <= l && r <= j)
        return lmax[x];
    int mid = (l + r) / 2;
    down(x);
    return max(get(x << 1, l, mid, i, j), get((x << 1) + 1, mid + 1, r, i, j));
}
void solve() {}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag ".inp", "r")) {
        freopen(tag ".inp", "r", stdin);
        freopen(tag ".out", "w", stdout);
    }
    cin >> n >> m;
    memset(lazy, 0, sizeof(lazy));
    // memset(lmax, 0, sizeof(lmax));
    int x, y, z;
    while(m--) {
        cin >> dk;
        if(dk == 0) {
            cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        } else {
            cin >> x >> y;
            cout << get(1, 1, n, x, y) << '\n';
        }
    }
    // solve();
}
/*
#include<bits/stdc++.h>
#define tag "qmax2"
#define int long long
const int N = 1e6+9;
using namespace std;
int a[N], m, n, lmax[4*N], lazy[4*N], L[4*N], R[4*N], dk;
void down(int x){
    int t = lazy[x];
    lazy[x<<1] += t;
    lmax[x<<1] += t;

    lazy[(x<<1)+1] += t;
    lmax[(x<<1)+1] += t;
    lazy[x] = 0;
    //lmax[x] += t;
}
void update(int x, int l, int r, int i, int j, int k){
    if(l > j || r < i)
        return;
    if(i <= l && r <= j){
        lmax[x] += k;
        lazy[x] += k;
        return;
    }
    int mid = (l+r)/2;
    down(x);
    update(x<<1, l, mid, i, j, k);
    update((x<<1)+1, mid+1, r, i, j, k);
    lmax[x] = max(lmax[x<<1], lmax[(x<<1)+1]);
}
int get(int x, int l, int r, int i, int j){
    if(l > j || r < i)
        return INT_MIN;
    if(i <= l && r <= j)
        return lmax[x];
    int mid = (l+r)/2;
    down(x);
    return max(get(x<<1, l, mid, i, j), get((x<<1)+1, mid+1, r, i, j));
}

int32_t main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> m;
    memset(lazy, 0, sizeof(lazy));
    //memset(lmax, 0, sizeof(lmax));
    int x, y, z;
    while(m--){
        cin >> dk;
        if(dk == 0){
            cin >> x >> y >> z;
            update(1, 1, n, x, y, z);
        }
        else{
            cin >> x >> y;
            cout<<get(1, 1, n, x, y)<<'\n';
        }
    }
    //solve();
}
*/