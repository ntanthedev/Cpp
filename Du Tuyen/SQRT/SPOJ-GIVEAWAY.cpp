//problem "SPOJ-GIVEAWAY"
//created in 23:36:20 - Mon 05/08/2024

#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5 + 9;

int n, a[N];
vector<int> s[N];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    int sz = sqrt(n);
    int m = n / (sz - 1) + 1; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s[i / sz].emplace_back(a[i]);
    }

    for(int i = 0; i < m; i++) 
        sort(all(s[i]));

    int Q;
    cin >> Q;
    while(Q--) {
        int c, x, y, z, cnt = 0;
        cin >> c >> x >> y;
        if(!c) {
            cin >> z;
            x--, y--;
            if(x / sz == y / sz) {
                for(int i = x; i <= y; i++) 
                    if(a[i] >= z) 
                        cnt++;    
                cout << cnt << '\n';
                continue;
            }

            for(int i = x; i <= (x / sz + 1) * sz - 1; ++i) 
                if(a[i] >= z) 
                    cnt++;

            for(int i = y / sz * sz; i <= y; i++) 
                if(a[i] >= z) 
                    cnt++;
            
            for(int i = x / sz + 1; i < y / sz; i++) { 
                int t = (lower_bound(all(s[i]), z) - s[i].begin());
                cnt += s[i].size() - t;
            }
            
            cout << cnt << '\n';
        }
        else {
            x--;
            int t = x / sz;
            auto it = lower_bound(all(s[t]), a[x]) - s[t].begin();
            s[t][it] = y;
            sort(all(s[t]));
            a[x] = y;
        }
    }
}