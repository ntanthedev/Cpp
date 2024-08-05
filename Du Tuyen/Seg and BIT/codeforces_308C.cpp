//Written by: ntannn_
//created in 10:35:37 - Sun 04/08/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

string s;
int q, n;

struct pt {
    int val, close, open;
} tree[4 * N];

pt combine (pt x, pt y) {
    pt z;
    int t = min(x.open, y.close);
    z.val = x.val + y.val + t * 2;
    z.open = x.open - t + y.open;
    z.close = x.close - t + y.close;
    return z;
}

/*
))) (((

((() ))
*/
void build(int id, int l, int r) {
    if(l == r) {
        tree[id].val = 0;
        tree[id].close = (s[l] == ')');
        tree[id].open = (s[l] == '(');
    }
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
    }
}

pt get(int id, int l, int r, int u, int v) {
    if(l > v || r < u) {
        return {0, 0, 0};
    }

    if(u <= l && r <= v) {
        return tree[id];
    }

    int mid = (l + r) / 2;
    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void solve() {
    cin >> s;
    n = s.size();
    s = ' ' + s;

    cin >> q;
    build(1, 1, n);

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << get(1, 1, n, u, v).val << '\n' ;
    }
}

#define task ""
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}