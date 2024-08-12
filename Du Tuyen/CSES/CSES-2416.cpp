//problem "CSES-2416"
//created in 21:35:08 - Sun 11/08/2024

#include <iostream>
#include <stack>

using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

struct pt {
    ll max, val, lens, sum, suf;

    bool operator ==(pt x) {
        return (max == x.max && val == x.val && lens == x.lens && sum == x.sum && suf == x.suf);
    }

} tree[4 * N];

ll n, q, w[N], s[N], max_right[N];

int walking(ll x, int L, int id = 1, int l = 1, int r = n) {

    cerr << "wk: " << x << " " << L << " " << id << " " << l << " " << r << '\n';
    if(w[tree[id].max] < x) 
        return -1;

    if(r < L) 
        return -1;

    if(l == r) 
        return l;

    int res = -1;
    int mid = (l + r) / 2;
    
    if(w[tree[id * 2].max] >= x) 
        res = walking(x, L, id * 2, l, mid);
    
    if(res == -1)
        res = walking(x, L, id * 2 + 1, mid + 1, r);
    return res;
}
// dung stack de tim

inline void dbg(pt t) {
    // cerr << t.max << " " << t.val << " " << t.lens << " " << t.sum << " " << t.suf << '\n';
}

pt combine(pt a, pt b) {
    pt x;
    pt tmp = {0LL, 0LL, 0LL, 0LL};
    if(a == tmp)
        return b;
    if(b == tmp)
        return a;
    x.lens = a.lens + b.lens;
    x.sum = a.sum + b.sum;
    if(w[a.max] > w[b.max]) {
        x.max = a.max;
        x.val = a.val + w[a.max] * b.lens - b.sum;
        x.suf = w[a.max] * b.lens - b.sum + a.suf;
    }
    else {
        x.max = b.max;
        x.val = a.val + b.val;
        // int it = walking(w[a.max], a.max + 1);
        int it = max_right[a.max];
        ll val = w[a.max] * (it - 1 - a.max) - (s[it - 1] - s[a.max]) - a.suf;
        // cerr << it << '\n';
        // cerr << a.max << " " << it - 1 - a.max << " " << (s[it - 1] - s[a.max]) << " " << a.suf << '\n';
        x.val += val;
        x.suf = b.suf;
    }
    return x;
}

void build(int id, int l, int r) {
    if(l == r) {
        tree[id] = {l, 0, 1, w[l]};
    }
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
    }
    // cerr << "\x1b[31m------------------ \n";
    // cerr << id << " " << l << " " << r << "\n";
    // cerr << tree[id].max << " " << tree[id].val << " " << tree[id].lens << " " << tree[id].sum << " " << tree[id].suf << '\n';
    // // cerr << "--------------\n";
    // cerr << "------------------\e[39m \n";
}

pt query(int u, int v, int id = 1, int l = 1, int r = n) {
    // cerr << "qr: " << u << " " << v << " " << id << " " << l << " " << r << '\n';
    if(u > r || v < l) {
        // cout << "th1\n";
        return {0LL, 0LL, 0LL, 0LL};
    }
    
    if(u <= l && r <= v) {
        // cout << "th2\n";
        return tree[id];
    }

    int mid = (l + r) / 2;
    // pt x = combine(query(u, v, id * 2, l, mid), query(u, v, id * 2 + 1, mid + 1, r));
    // cout << "th3: ";
    // dbg(x);
    return combine(query(u, v, id * 2, l, mid), query(u, v, id * 2 + 1, mid + 1, r));
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> q;

    s[0] = w[0] = 0LL;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        s[i] = s[i - 1] + w[i];
    }
    
    stack<ll> st;

    for(int i = n; i >= 1; i--) {
        while(!st.empty() && w[st.top()] < w[i])
            st.pop();
        max_right[i] = (st.empty() ? n + 1 : st.top());
        st.push(i);
    }    

    // cerr << "max_right: \n";
    // for(int i = 1; i <= n; i++) 
    //     cerr << max_right[i] << " ";
    // cerr << '\n';

    build(1, 1, n);

    // cerr << "\x1b[31mstart debug: \n";
    // cerr << "s: ";
    // for(int i = 1; i <= n; i++) 
    //     cerr << s[i] << " ";
    // cerr << "\nend of debug\e[39m \n";
    
    // auto t = combine(tree[2], tree[6]);
    // cerr << t.max << " " << t.val << " " << t.lens << " " << t.sum << " " << t.suf << '\n';
    // pt xx = {0LL, 0LL, 0LL, 0LL};
    // t = combine(xx, t);
    // cerr << t.max << " " << t.val << " " << t.lens << " " << t.sum << " " << t.suf << '\n';
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b).val << '\n';
    }
}

/*
5 3
2 10 4 2 5
3 5
2 2
1 4
max, val, lens, sum, suf;

5 1
2 10 4 2 5
1 4
*/