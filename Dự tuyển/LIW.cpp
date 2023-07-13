#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
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

const int N = 1e5+10;
const ll MOD = 1e9+7;

ll a[N], m, n, c[N];

ii b[N];

map<ll, ll> M;

vii ans;

bool cmp(ii x, ii y) {
    return x.se < y.se;
}

void solve() {
    for(int i = 1; i <= n; i++) {
        if(M[b[i].fi]) {
            ans.pb(b[i]);
            M[b[i].fi]--;
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << '\n'; 
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].fi << " " << ans[i].se << '\n';
    }
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        M[a[i]]++;
    }
    for(int i = 1; i <= n; i++)
        cin >> b[i].se;
    for(int i = 1; i <= n; i++)
        cin >> b[i].fi;
}
#define task "LIW"
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