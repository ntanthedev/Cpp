//problem "221D"
//created in 15:48:10 - Tue 06/08/2024

#include<bits/stdc++.h>

const int N = 1e5 + 5;

using namespace std;

int n, Q, sz, ans = 0, lef = 0, rig = 0;
int res[N], cnt[N], a[N];

struct query {
    int l, r, id;

    bool operator <(query x)  {
        return make_pair(l / sz, r) < make_pair(x.l / sz, x.r);
    }

    // query(int _l, int _r, int _id): l(_l), r(_r), id(_id) {};
} q[N];

void add(int i) {
    if(a[i] > n) 
        return;
    cnt[a[i]]++;
    if(cnt[a[i]] == a[i]) 
        ans++;
    if(cnt[a[i]] == a[i] + 1)
        ans--;
}

void rmv(int i) {
    if(a[i] > n)
        return;
    cnt[a[i]]--;
    if(cnt[a[i]] == a[i]) 
        ans++;
    if(cnt[a[i]] + 1 == a[i]) 
        ans--;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> Q;
    
    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    sz = sqrt(n);

    for(int i = 1; i <= Q; i++) {
        int l, r;
        cin >> l >> r;
        q[i] = {l, r, i};
    }

    sort(q + 1, q + 1 + Q);

    lef = rig = q[1].l;
    add(q[1].l);
    for(int i = 1; i <= Q; i++) {
        while(lef < q[i].l) rmv(lef++);
        while(rig > q[i].r) rmv(rig--);
        while(lef > q[i].l) add(--lef);
        while(rig < q[i].r) add(++rig);
        res[q[i].id] = ans;
    }

    for(int i = 1; i <= Q; i++) 
        cout << res[i] << '\n';
}