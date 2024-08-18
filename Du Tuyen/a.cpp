//problem "a"
//created in 22:51:50 - Sat 17/08/2024

#include<iostream>
#include<map>

using namespace std;

const int N = 1e5 + 5;
typedef long long ll;

int n, m = 0;
int tree[4 * N], a[N];
map<long long, int> M;

void update(int id, int l, int r, int v, int w) {
    if(l > v || r < v)
        return;
    if(l == r) 
        return tree[id] += w, void();
    int mid = (l + r) / 2;
    update(id * 2, l, mid, v, w);
    update(id * 2 + 1, mid + 1, r, v, w);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if(l > v || r < u) 
        return 0;
    if(u <= l && r <= v)
        return tree[id];
    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        M[a[i]]++;
    }    
    
    for(auto &it : M) {
        it.second = ++m;
    }

    for(int i = 1; i <= n; i++) 
        a[i] = M[a[i]];

    for(int i = 1; i <= n; i++) cerr << a[i] << " "; cerr << '\n';

    for(int i = 1; i <= n; i++) {
        update(1, 1, m, a[i], get(1, 1, m, 1, a[i] - 1) + 1);
        cerr << i << ": " << get(1, 1, m, 1, a[i]) << '\n';
    }

    cout << get(1, 1, m, 1, m);
}