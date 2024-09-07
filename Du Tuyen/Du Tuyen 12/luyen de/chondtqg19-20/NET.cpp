#include<bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef long long ll;
const int N = 3e5 + 5;

int n, t, ans = 0;
pair<ll, ll> a[N];
multiset<ll> m;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("NET.inp","r",stdin);
    freopen("NET.out","w",stdout);

    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].se += a[i].fi;
    }

    sort(a + 1, a + 1 + n);

    for(int i = 1; i <= n; i++) {
//        cerr << a[i].fi << " " << a[i].se << '\n';
        while(!m.empty() && *m.begin() < a[i].fi - t)
            m.erase(m.begin());
//        cerr << "check mts: "; for(auto it : m) cerr << it << " "; cerr << '\n';
        if(!m.empty() && *m.begin() <= a[i].fi) {
            ans++;
//            cerr << "check: " << ans << '\n';
            m.erase(m.begin());
        }
        m.insert(a[i].se);
    }

    cout << ans;
}

/*
den dua nao trong va con trong m thi co lay
neu da full may thi moi bat
*/
