//problem "a"
//created in 15:55:16 - Sun 21/07/2024

#include<bits/stdc++.h>

#define int long long 
const int N = 2e5 + 5;

using namespace std;

struct tree {
    int val[4 * N], pre[4 * N], suf[4 * N], len[4 * N];

    void combine(int id) {
        val[id] = max({val[id * 2 + 1], val[id * 2], suf[id * 2] + pre[id * 2 + 1]});
        len[id] = len[id * 2] + len[id * 2 + 1];
        pre[id] = pre[id * 2];
        suf[id] = suf[id * 2 + 1];
        if(len[id * 2] == pre[id * 2])
            pre[id] += pre[id * 2 + 1]; 
        if(len[id * 2 + 1] == suf[id * 2 + 1])
            suf[id] += suf[id * 2];
    }

    void update(int id, int l, int r, int pos, int w) {
        if(l > pos || r < pos)
            return;
        if(l == r) {
            val[id] = pre[id] = suf[id] = w;
            len[id] = 1;
            return;
        }
        int mid = (l + r) / 2;
        update(id * 2, l, mid, pos, w);
        update(id * 2 + 1, mid + 1, r, pos, w);
        combine(id);
    }

} it[2];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    int n = s.size();

    for(int i = 0; i < n; i++) {
        it[s[i] - '0'].update(1, 1, n, i + 1, 1);
        it[1 - (s[i] - '0')].update(1, 1, n, i + 1, 0);
    }
    int Q, x;
    cin >> Q;
    while(Q--) {
        cin >> x;
        x--;
        it[s[x] - '0'].update(1, 1, n, x + 1, 0);
        it[1 - (s[x] - '0')].update(1, 1, n, x + 1, 1);
        s[x] = char(('1' - s[x]) + '0');
        cout << max(it[0].val[1], it[1].val[1]) << " ";
    }
}