#include <cmath>
#include <iostream>

using namespace std;

const int N = 1e6 + 5;
long long t[N << 2], lz1[N << 2], lz2[N << 2];
void build(int id, int l, int r) {
    if(l == r)
        return cin >> t[id], void();
    int m = (l + r) >> 1;
    build(id << 1, l, m);
    build(id << 1 | 1, m + 1, r);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
void psh(int id, int l, int r, int mid) {
    if(lz1[id] != 0) {
        t[id << 1] += 1ll * (mid - l + 1) * (mid - l + 2) / 2 * lz1[id];
        t[id << 1 | 1] += 1ll * (mid - l + 1) * (r - mid) * lz1[id] + 1ll * (r - mid + 1) * (r - mid) / 2 * lz1[id];
        lz1[id << 1] += lz1[id], lz1[id << 1 | 1] += lz1[id];
        lz2[id << 1 | 1] += (mid - l + 1) * lz1[id];
        lz1[id] = 0;
    }
    if(lz2[id] != 0) {
        t[id << 1] += lz2[id] * (mid - l + 1);
        t[id << 1 | 1] += lz2[id] * (r - mid);
        lz2[id << 1] += lz2[id], lz2[id << 1 | 1] += lz2[id];
        lz2[id] = 0;
    }
}
void upd(int id, int l, int r, int u, int v) {
    if(l > v || r < u)
        return;
    if(u <= l && r <= v) {
        t[id] +=
            1ll * (r - l + 1) * (r - l + 2) / 2 + 1ll * (l - u) * (r - l + 1);
        if(l != r) {
            ++lz1[id];
            lz2[id] += l - u;
        }
        return;
    }
    int m = (l + r) >> 1;
    psh(id, l, r, m);
    upd(id << 1, l, m, u, v);
    upd(id << 1 | 1, m + 1, r, u, v);
    t[id] = t[id << 1] + t[id << 1 | 1];
}
long long qry(int id, int l, int r, int u, int v) {
    if(l > v || r < u)
        return 0;
    if(u <= l && r <= v)
        return t[id];
    int m = (l + r) >> 1;
    psh(id, l, r, m);
    return qry(id << 1, l, m, u, v) + qry(id << 1 | 1, m + 1, r, u, v);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("a.inp","r",stdin);
    // freopen("a.out","w",stdout);
    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    while(q--) {
        int tp, l, r;
        cin >> tp >> l >> r;
        if(tp == 1)
            upd(1, 1, n, l, r);
        else
            cout << qry(1, 1, n, l, r) << "\n";
    }
    return 0;
}