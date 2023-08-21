#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
typedef long long ll;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

ll node[N], lazy[N], res[N];

void day(ll id, ll l, ll r) {
    if(res[id] == 1) {
        node[id * 2] = node[id * 2 + 1] = 0;
        lazy[id * 2] = lazy[id * 2 + 1] = 0;
        res[id * 2] = res[id * 2 + 1] = 1;
    }
    res[id] = 0;
    int mid = (l + r)/2;
    lazy[id * 2] ^= lazy[id];
    lazy[id * 2 + 1] ^= lazy[id];
    if((mid - l + 1) % 2 == 1) {
        node[id * 2] ^= lazy[id];
    }
    if((r - mid) % 2 == 1) {
        node[id * 2 + 1] ^= lazy[id];
    }
    lazy[id] = 0;
}

void update(ll id, ll l, ll r, ll d, ll c, ll f) {
    if((l > r) || (l > c) || (r < d)) {
        return;
    }
    if((d <= l) && (r <= c)) {
        if((r - l + 1) % 2 == 1)
            node[id] ^= f;
        lazy[id] ^= f;
        return;
    }
    int mid = (l + r)/2;
    day(id, l, r);
    update(id * 2, l, mid, d, c, f);
    update(id * 2 + 1, mid + 1, r, d, c, f);
    node[id] = node[id * 2] ^ node[id * 2 + 1];
}

ll get_xor(ll id, ll l, ll r, ll d, ll c) {
    if(l > c || r < d) {
        return 0;
    }
    if((d <= l) && (r <= c))
        return node[id];
    int mid = (l + r)/2;
    day(id, l, r);
    return (get_xor(id * 2, l, mid, d, c) ^ get_xor(id * 2 + 1, mid + 1, r, d, c));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, Q, c, l, r, f;
    read(n), read(Q);
    while(Q--) {
        int c;
        read(c);
        if(c == 1) {
            read(l), read(r), read(f);
            update(1, 1, n, l, r, f);
        } else {
            read(l), read(r);
            cout << get_xor(1, 1, n, l, r) << '\n';
            node[1] = 0, res[1] = 1, lazy[1] = 0;
        }
    }
}