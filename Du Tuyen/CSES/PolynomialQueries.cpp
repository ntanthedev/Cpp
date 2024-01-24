//template for some simple code by ntannn_
//created in 08:59:00 - Wed 24/01/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define left id*2
#define right id*2+1
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 2e5 + 10;
const ll MOD = 1e9 + 7;

struct pt {
    ll lz1, lz2, sum;
};
pt tree[4 * N];

ll n, arr[N], Q;

void build(int id, int l, int r) {
    tree[id].lz1 = 0;
    tree[id].lz2 = 0;
    if(l == r)
        tree[id].sum = arr[l];
    else {
        int mid = (l + r)/2;
        build(left, l, mid);
        build(right, mid + 1, r);
        tree[id].sum = (tree[left].sum + tree[right].sum);
    }
}

void update(int id, int l, int r, int a, int b) {
    if(tree[id].lz1 != 0 || tree[id].lz2 != 0) {
        tree[id].sum += ((r + l) * (r - l + 1) / 2 - tree[id].lz2) * tree[id].lz1;
        if(l != r) {
            tree[left].lz1 += tree[id].lz1;
            tree[left].lz2 += tree[id].lz2;
            tree[right].lz1 += tree[id].lz1;
            tree[right].lz2 += tree[id].lz2;
        }
        tree[id].lz1 = 0;
        tree[id].lz2 = 0;
    }
    if(l > b || r < a)
        return;
    if(a <= l && r <= b) {
        tree[id].sum += ((r + l) * (r - l + 1) / 2 - (r - l + 1) * (a - 1));
        if(l != r) {
            tree[left].lz1++;
            tree[left].lz2 += (a - 1);
            tree[right].lz1++;
            tree[right].lz2 += (a - 1);
        }
        return;
    }
    int mid = (l + r) / 2;
    update(left, l, mid, a, b);
    update(right, mid + 1, r, a, b);
    tree[id].sum = tree[left].sum + tree[right].sum;
}
ll get(int id, int l, int r, int a, int b) {
    if(tree[id].lz1 != 0) {
        tree[id].sum += ((r + l) * (r - l + 1) /  2 - tree[id].lz2 * (r - l + 1)) * tree[id].lz1;
        if(l != r) {
            tree[left].lz1 += tree[id].lz1;
            tree[left].lz2 += tree[id].lz2;
            tree[right].lz1 += tree[id].lz1;
            tree[right].lz2 += tree[id].lz2;
        }
        tree[id].lz1 = 0;
        tree[id].lz2 = 0;
    }
    if(a > r || b < l)
        return 0;
    if(a <= l && r <= b)
        return tree[id].sum;
    int mid = (l + r) / 2;
    return get(left, l, mid, a, b) + get(right, mid + 1, r, a, b);
}

void solve() {
    build(1, 1, n);
    while(Q--) {
        int c, a, b;
        cin >> c >> a >> b;
        if(c == 1)
            update(1, 1, n, a, b);
        else
            cout << get(1, 1, n, a, b) << '\n';
    }
}

void init() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) 
        cin >> arr[i];
    
}

#define task "PolynomialQueries"
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
        init();
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}