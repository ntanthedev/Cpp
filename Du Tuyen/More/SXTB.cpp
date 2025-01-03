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
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, m;
vi ans;
struct pt {
    ll fi, se, vt;
};
pt a[N];
map<ll, ll> M;

bool cmp(pt x, pt y) {
    return (x.fi < y.fi || (x.fi == y.fi && (x.se < y.se || (x.se == y.se && x.vt < y.vt))));
}

ll chat(ll x) {
    int l = 1, r = n;
    while(l < r) {
        int mid = (l+r)/2;
        if(a[mid].fi <= x)
            l = mid;
        else 
            r = mid-1;
    }
    return l;
}
void solve() {
    pt b = a[m];
    ans.pb(m);
    sort(a+1, a+1+n, cmp);
    while(true) {
        ll t = upper_bound(a+1, a+1+n, (b.fi, 0, 0)) - a - 1;
        while(M[a[t].vt]) {
            t--;

        }

    }
}

void init() {
    read(n), read(m);
    for(int i = 1; i <= n; i++)
        read(a[i].fi);
    for(int i = 1; i <= n; i++)
        read(a[i].se);
}
#define task ""
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}