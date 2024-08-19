//created in 2024-08-19-16.22.03 in Code::Blocks 20.03
#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

const int inf = -1e9;
const int N = 5e5 + 5;
typedef pair<int, int> ii;

int n, Q, m = 0;
ii a[N], tree[4 * N];
int last[N];
map<int, int> M;

ii combine (ii x, ii y) {
    return ((x.fi - x.se) <= (y.fi - y.se) ? x : y);
}

void build (int id, int l, int r) {
//    cout << id << " " << l << " " << r << ": ";
    if(l == r) {
        tree[id] = {l, a[l].se};
    }
    else {
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
    }
//    cout << "{" << tree[id].fi << ", " << tree[id].se << "}" << '\n';
}

ii query (int id, int l, int r, int u, int v) {
    if(l > v || r < u)
        return {0, inf};
    if(u <= l && r <= v) {
        return (tree[id].se >= u ? tree[id] : make_pair(0, inf));
    }
    int mid = (l + r) / 2;
    return combine(query(id * 2, l, mid, u, v), query(id * 2 + 1, mid + 1, r, u, v));
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    if(fopen("test.inp","r")) {
        freopen("test.inp","r",stdin);
        freopen("a.out","w",stdout);
    }

    cin >> n >> Q;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        last[i] = inf;
        M[a[i].fi] = 1;
    }

    for(auto &it : M) {
        it.se = ++m;
    }

    for(int i = 1; i <= n; i++) {
        a[i].fi = M[a[i].fi];
        a[i].se = last[a[i].fi];
        last[a[i].fi] = i;
    }

//    for(int i = 1; i <= n; i++) cout << a[i].fi << " "; cout << '\n';
//    for(int i = 1; i <= n; i++) cout << a[i].se << " "; cout << '\n';

    build(1, 1, n);

    while(Q--) {
        int l, r;
        cin >> l >> r;
        ii ans = query(1, 1, n, l, r);
        cout << (ans.se != inf ? ans.fi - ans.se : -1) << '\n';
    }
}
