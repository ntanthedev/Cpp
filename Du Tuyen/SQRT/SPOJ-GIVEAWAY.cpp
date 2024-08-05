//problem "SPOJ-GIVEAWAY"
//created in 23:36:20 - Mon 05/08/2024

#include<bits/stdc++.h>

#define int long long

#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5 + 5;

int n, a[N];
vector<int> s[N];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    int sz = sqrt(n);
    int m = (n + sz - 1) / sz; 
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
                    if(a[i] >= c) 
                        cnt++;    
                cout << cnt << '\n';
                continue;
            }

            for(int i = x; i <= (x / sz + 1) * sz - 1; ++i) 
                if(a[i] >= z) 
                    cnt++;

            for(int i = (y / sz) * sz; i <= y; i++) 
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
            for(int i = 0; i < s[x / sz].size(); ++i) {
                if(s[x / sz][i] == a[x]) {
                    s[x / sz][i] = y;
                    a[x] = y;
                    sort(all(s[x / sz]));
                    break;
                }
            }
        }
    }
}