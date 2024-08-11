//problem "CSES-2416"
//created in 21:35:08 - Sun 11/08/2024

#include <iostream>

using namespace std;

const int N = 2e5 + 5;
typedef long long ll;

struct pt {
    ll max, val, lens, sum;
} tree[4 * N];

ll n, q, w[N], s[N];

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

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
pt combine(pt a, pt b) {
    pt x;
    x.lens = a.lens + b.lens;
    x.sum = a.sum + b.sum;
    if(w[a.max] > w[b.max]) {
        x.max = a.max;
        x.val = a.val + a.max * b.lens - b.sum;
    }
    else {
        x.max = b.max;
        x.val = a.val + b.val;
        int it = walking(w[a.max], a.max + 1);
        ll val = w[a.max] * (it - 1 - a.max) - (s[it - 1] - s[a.max]);
        cerr << walking(w[a.max], a.max + 1) << '\n';
        cerr << a.max << " " << it - 1 - a.max << " " << (s[it - 1] - s[a.max]) << '\n';
        x.val += val;
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
    cerr << "\x1b[31m------------------ \n";
    cerr << id << " " << l << " " << r << "\n";
    cerr << tree[id].max << " " << tree[id].val << " " << tree[id].lens << " " << tree[id].sum << '\n';
    // cerr << "--------------\n";
    cerr << "------------------\e[39m \n";
}

pt query(int u, int v, int id = 1, int l = 1, int r = n) {
    if(u > r || v < l)
        return {0LL, 0LL, 0LL, 0LL};
    
    if(u <= l && r <= v) {
        return tree[id];
    }

    int mid = (l + r) / 2;
    return combine(query(l, r, id * 2, l, mid), query(l, r, id * 2 + 1, mid + 1, r));
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> q;

    s[0] = w[0] = 0LL;
    for(int i = 1; i <= n; i++) {
        cin >> w[i];
        s[i] = s[i - 1] + w[i];
    }

    build(1, 1, n);

    cerr << "\x1b[31mstart debug: \n";
    cerr << "s: ";
    for(int i = 1; i <= n; i++) 
        cerr << s[i] << " ";
    cerr << "\nend of debug\e[39m \n";


    
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b).val << '\n';
    }
}