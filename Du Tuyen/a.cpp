//problem "Gopso"
//created in 07:31:40 - Thu 25/07/2024

#include<bits/stdc++.h>

#define int long long
#define fi first 
#define se second

using namespace std;

typedef pair<int, int> ii;

int n, q;

map<ii, ii> m;

ii find_par(ii x) {
    return (m[x].fi < 0 ? x : m[x] = find_par(m[x]));
}

void merge_par(ii a, ii b) {
    a = find_par(a);
    b = find_par(b);

    if(a != b) {
        if(a.fi < b.fi)
            swap(a, b);
        m[b].fi += m[a].fi;
        m[a] = b;
    }
}


signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    

    cin >> n >> q;

    vector<int> par(n + 1, -1);

    function<int(int)> Find = [&](int x) {
        return par[x] < 0 ? x : par[x] = Find(par[x]);
    };

    function<void(int, int)> Merge = [&](int x, int y) {
        x = Find(x);
        y = Find(y);

        if(x != y) {
            if(par[x] > par[y])
                swap(x, y);
            par[x] += par[y];
            par[y] = x;
        }
    };

    if(n <= 1000 && q <= 1000) {
        for(int i = 1, c, x, y; i <= q; ++i) {
            cin >> c >> x >> y;
            if(c == 1) {
                Merge(x, y);
            }
            if(c == 2) {
                for(int i = x; i <= y; i++) {
                    Merge(x, y);
                }
            }
            if(c == 3) {
                x = Find(x);
                y = Find(y);
                cout << (x == y ? "YES" : "NO");
            }
        }
    }

    else {
        bool check = 0;
        for(int i = 1, c, x, y; i <= q; ++i) {
            cin >> c >> x >> y;
            if(c == 1) {
                Merge(x, y);
            }
            if(c == 2) {
                if(!check) {
                    for(int i = 1; i <= n; ++i) 
                        m[{i, i}] = {-1, 0};
                    check = 1;
                }
                for(int i = x; i <= y; i++) {
                    Merge(x, y);
                }
            }
            if(c == 3) {
                x = Find(x);
                y = Find(y);
                cout << (x == y ? "YES" : "NO");
            }
        }
    }

}

/*
1 2 3 4 5 6 7 8 9
*/