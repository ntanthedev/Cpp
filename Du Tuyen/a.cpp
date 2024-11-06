#include<bits/stdc++.h> 

#define int int64_t

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "select"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;  

    vector<int> dd(n + 1, 0), cnt(n + 1, 0);
    map<int, int> m;
    int d = 0, ans = 0;


    for(int i = 1; i <= n; i++) {
        d += (s[i] == '+' ? 1 : -1);
        dd[i] = d;
        cnt[i] = m[d];
        m[d]++;
    }

    for(int i = 1; i <= n; i++) {
        ans += m[dd[i]] - cnt[i] * 2;
    }
    cout << ans;
}

/*
+ + - + - + + + -
1 2 1 2 1 2 3 4 3
*/
