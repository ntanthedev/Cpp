//problem "617E"
//created in 20:56:59 - Tue 06/08/2024

#include<bits/stdc++.h>

const int N = 5e5 + 5;

using namespace std;

int n, k, m, sz, ans = 0;
int cnt[1 << 20], a[N], res[N];

struct query {
    int l, r, id;

    bool operator <(query x) {
        return make_pair(l / sz, r) < make_pair(x.l / sz, x.r);
    }

} q[N];

void add(int i) {
    ans += cnt[a[i] ^ k];
    cnt[a[i]]++;
}

void rmv(int i) {
    cnt[a[i]]--;
    ans -= cnt[a[i] ^ k];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> k;
    
    sz = sqrt(n);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    sort(q + 1, q + 1 + m);

    int l = 1, r = 0;

    for(int i = 1; i <= m; i++) {
        while(r < q[i].r) add(++r);
        while(r > q[i].r) rmv(r--);
        while(l > q[i].l) add(--l);
        while(l < q[i].l) rmv(l--);
        res[q[i].id] = ans;
    }

    for(int i = 1; i <= m; i++) 
        cout << res[i] << '\n';
}