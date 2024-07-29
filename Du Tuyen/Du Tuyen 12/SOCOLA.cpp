// problem "SOCOLA"
// created in 07:48:58 - Mon 29/07/2024

#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define int int64_t
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

template<typename T> inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "SOCOLA"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, q;

    read(n), read(q);

    vector<int> a(n);

    for(auto& i: a) {
        read(i);
    }

    vector<pair<int, int>> query(q);
    bool check_sub_2 = 1;

    for(int i = 0; i < q; ++i) {
        read(query[i].first), read(query[i].second);
        if(i > 0 && query[i].first != query[i - 1].first)
            check_sub_2 = 0;
    }

    if(n * q <= 1e7) {
        sort(all(a));
        for(int i = 0; i < q; i++) {
            int k = query[i].first, m = query[i].second;
            int l = 0, r = n - 1, res = 0;
            while(l <= r) {
                int tl = (a[l] <= k ? a[l] : k - (a[l] - k));
                int tr = (a[r] <= k ? a[r] : k - (a[r] - k));
                if(tl < tr) 
                    res += tl, l++;
                else 
                    res += tr, r--;
                m--;
                if(!m) 
                    break;;
            }
            cout << res << '\n';
        }
    } else if(check_sub_2) {
        vector<int> b(n);
        int tmp_k = query[0].first;
        for(int i = 0; i < n; i++)
            b[i] = (a[i] <= tmp_k ? a[i] : tmp_k - (a[i] - tmp_k));
        sort(all(b));
        // dbg(b)
        for(int i = 1; i < n; ++i)
            b[i] += b[i - 1];
        // dbg(b)
        for(int i = 0; i < q; i++) {
            int m = query[i].second;
            cout << b[m - 1] << '\n';
        }
    } else {
        
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}

/*
5 2
1 9 22 10 19
1 9 10 19 22
1 1 0  -9 -12
l         r

7 4
1 5 4 3 7 11 9
5 4
5 7
5 3
5 5


*/
