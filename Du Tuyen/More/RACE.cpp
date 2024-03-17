#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second
#define all(x) x.begin(), x.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define task "RACE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n;
    cin >> n;
    vector<pair<int, int> > a(n), b(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i].fi, a[i].se = i + 1;
    for(int i = 0; i < n; i++)
        cin >> b[i].fi, b[i].se = i + 1;
    sort(all(a));
    sort(all(b));
    int l = 0, r = 0;
    vector<pair<int, int>> ans;
    while(l < a.size() && r < b.size()) {
        while(a[l].fi < b[r].fi) {
            ans.emplace_back(a[l].se, b.back().se);
            l++;
            b.pop_back();
        }
        if(l < a.size()  && r < b.size() && a[l].fi >= b[r].fi) 
            ans.emplace_back(a[l++].se, b[r++].se);
    }
    cout << "size: " << ans.size() << '\n';
    for(pair<int, int> i : ans)
        cout << i.fi << " " << i.se << '\n';
}