//problem "a"
//created in 21:08:59 - Mon 22/04/2024

#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second 
const int N = 1e3 + 2;

using namespace std;

int n, m;
int cnt[N];
vector<pair<int, int>> a;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) 
        for(int j = 1, x; j <= m; j++) {
            cin >> x;
            a.emplace_back(x, i);
        }
    
    sort(a.begin(), a.end());

    int l = 0, r = 0, d = 0, ans = LLONG_MAX;

    while(r < n * m) {
        d += (cnt[a[r].se] == 0);
        cnt[a[r].se]++;
        while(l < r && d == n) {
            if(d == n)
                ans = min(ans, a[r].fi - a[l].fi);
            d -= (--cnt[a[l].se] == 0);
            l++;
        }
        r++;
    }

    cout << ans;
}