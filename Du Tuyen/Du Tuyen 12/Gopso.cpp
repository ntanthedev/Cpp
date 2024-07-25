//problem "Gopso"
//created in 08:41:34 - Thu 25/07/2024

#include<bits/stdc++.h>

#define int long long 

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "Gopso"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, q;
    cin >> n >> q;

    vector<int> par(n + 5, -1);
    vector<int> next(n + 5);

    for(int i = 0; i <= n; i++) {
        next[i] = i + 1;
    }

    function<int(int)> find_par = [&](int x) {
        return par[x] < 0 ? x : par[x] = find_par(par[x]);
    };

    function<void(int, int)> merge_par = [&](int x, int y) {
        x = find_par(x);
        y = find_par(y);

        if(x != y) {
            if(par[x] > par[y])
                swap(x, y);
            par[x] += par[y];
            par[y] = x;
        }
    };

    function<int(int)> find_next = [&](int x) {
        return find_par(x) != find_par(x - 1) ? x : next[x] = find_next(next[x]);
    };

    for(int i = 1, a, b, c; i <= q; ++i) {
        cin >> c >> a >> b;
        if(c == 1) {
            if(a == b)
                continue;
            merge_par(a, b);
        }
        else if(c == 2) {     
            if(a == b) 
                continue;       
            for(int i = find_next(next[a]); i <= b; i = find_next(i)) {
                merge_par(i, i - 1);
            }
        }
        else {
            cout << (find_par(a) == find_par(b) ? "YES" : "NO") << '\n';
        }
    }
}
/*
8 6
3 2 5
1 2 5
3 2 5 
2 4 7
2 1 2 
3 1 7
*/