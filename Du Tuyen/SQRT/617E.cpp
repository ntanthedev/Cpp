//problem "617E"
//created in 20:56:59 - Tue 06/08/2024

#include<bits/stdc++.h>

#define int long long
const int N = 5e5 + 5;

using namespace std;

int n, k, m, sz, ans = 0;
int cnt[4 * N], a[N], res[N], s[N];

struct query {
    int l, r, id;

    bool operator <(query x) {
        return make_pair(l / sz, r) < make_pair(x.l / sz, x.r);
    }

} q[N];

void add(int x) {
    ans += cnt[x ^ k];
    cnt[x]++;
}

void rmv(int x) {
    cnt[x]--;
    ans -= cnt[x ^ k];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m >> k;
    
    sz = sqrt(n);
    s[0] = 0;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    sort(q + 1, q + 1 + m);

    int l = 1, r = 0;
    add(s[0]);
    for(int i = 1; i <= m; i++) {
        while(r < q[i].r) add(s[++r]);
        while(r > q[i].r) rmv(s[r--]);
        while(l > q[i].l) add(s[--l - 1]);
        while(l < q[i].l) rmv(s[l++ - 1]);
        res[q[i].id] = ans;
    }

    for(int i = 1; i <= m; i++) 
        cout << res[i] << '\n';
}