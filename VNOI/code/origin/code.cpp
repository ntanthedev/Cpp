#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 2e5+10;
const ll MOD = 1e9+7;

ll n, k, a[N], s[N];
// clock_t start, endd;
void solve() {
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ll res = a[i];
        for(int j = i; j <= n; j++) {
            if(s[j] - s[i-1] < k) continue;
            res = (s[j] - s[i-1])/(j-i+1);
            ans = max(ans, res);
        }
    }
    cout << ans;
    // endd = clock();
    // double time_elapsed = (double)(endd - start) / CLOCKS_PER_SEC;
    // cout << "time: " << time_elapsed;
}

ll gmax = 0;
void init() {
    read(n), read(k);
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        read(a[i]);
        s[i] = s[i-1] + a[i];
        if(a[i] >= k)
            gmax = max(gmax, a[i]);
    }
}

#define task "code"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    // start = clock();
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        if(gmax)
            return cout << gmax, 0;
        solve();
    }
}