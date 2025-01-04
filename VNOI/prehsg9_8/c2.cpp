//problem "cau 1"
//created in 20:25:52 - Fri 03/01/2025

#include<bits/stdc++.h>

#define int long long

using namespace std;

// dp
struct Sub1 {
    int n, x;
    vector<int> f, a;

    Sub1(int _n, int _x): n(_n), x(_x), f(n + 2, INT_MAX), a(n + 1) {
        for(int i = 1; i <= n; i++) 
            cin >> a[i];
    }

    int solve() {
        f[0] = 0; a[n + 1] = 0;

        for(int i = 1; i <= n + 1; i++) 
            for(int j = max(0LL, i - x); j < i; j++) 
                f[i] = min(f[i], f[j] + a[i]);
            
        return f[n + 1];
    }
};

//tree nhung ma sai me roi
struct Sub2 {
    int n, x;
    vector<int> a, f, tree;        

    Sub2(int _n, int _x): n(_n), x(_x), a(n + 2), f(n + 2), tree((n + 2) << 2) {
        for(int i = 1; i <= n; i++) 
            cin >> a[i];
    }

    void update(int id, int l, int r, int u, int w) {
        if(l > u || r < u) 
            return;
        if(l == r) 
            return tree[id] = w, void();
        int mid = (l + r) << 2;
        update(id << 1, l, mid, u, w);
        update(id << 1 | 1, mid + 1, r, u, w);
        tree[id] = min(tree[id << 1], tree[id << 1 | 1]);
    }

    int get(int id, int l, int r, int u, int v) {
        if(l > v || r < u) 
            return 0;
        if(l >= u && r <= v) 
            return tree[id];
        int mid = (l + r) << 2;
        return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
    }

    int solve() {
        f[0] = 0; a[n + 1] = 0;

        for(int i = 1; i <= n + 1; i++) 
            update(1, 0, n, i, f[i] = get(1, 0, n, max(0LL, i - x), i - 1) + a[i]);
            
        return f[n + 1];
    }
};

// deque
struct Sub3 {
    int n, x, ans;
    vector<int> a, f;        

    Sub3(int _n, int _x): n(_n), x(_x), a(n + 1), f(n + 2, INT_MAX) {
        for(int i = 1; i <= n; i++) 
            cin >> a[i];
    }

    int solve() {
        deque<int> dq;
        f[0] = 0;

        for(int i = 1; i <= n + 1; i++) {
            while(dq.size() && f[dq.back()] >= f[i - 1]) 
                dq.pop_back();
            dq.push_back(i - 1);
            if(i - dq.front() > x)
                dq.pop_front();
            f[i] = f[dq.front()] + a[i];
        }

        // for(int i = 1; i <= n + 1; i ++) 
        //     cerr << f[i] << " " ;
        // cerr << '\n';

        return f[n + 1];
    }
};


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "a"
    if(fopen(task ".inp", "r")) {
        freopen( "test.inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, x;
    cin >> n >> x;
    
    Sub3 ans(n, x);
    cout << ans.solve();
}

/*
x = 1
i-1 i
*/