//problem "CSES1655"
//created in 08:31:05 - Sat 27/07/2024

#include<bits/stdc++.h>

const int N = 2e5 + 5;

using namespace std;

int n, trie[N * 20][2], cnt = 0, ans = 0;

void Add(int x) {
    int cur = 0;
    for(int i = 31; i >= 0; --i) {
        int u = (x >> i & 1);
        if(!trie[cur][u])
            trie[cur][u] = ++cnt;
        cur = trie[cur][u];
    }
}

int get(int x) {
    int cur = 0, res = 0;
    for(int i = 31; i >= 0; --i) {
        int u = (x >> i & 1);
        if(trie[cur][1 ^ u])
            res += (1 << i),
            cur = trie[cur][1 ^ u];
        else 
            cur = trie[cur][u];
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    int s = 0;
    for(int i = 1, x; i <= n; i++) {
        Add(s);
        cin >> x;
        s ^= x;
        ans = max(ans, get(s));
    }
    cout << ans;
}
/*
4
5 1 5 9
*/