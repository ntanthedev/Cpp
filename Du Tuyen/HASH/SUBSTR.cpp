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
typedef unsigned long long ull;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+500;
const ll MOD = 1e9+7;

string a, b;
ll POW[N], Hasha[N], Hashb, n, m;
ll base = 311;

ll get_hasha(int i, int j) {
   return (Hasha[j] - Hasha[i-1] * POW[j-i+1] + MOD * MOD) % MOD;
}

void solve() {
    n = a.size();
    m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    POW[0] = 1;
    for(ll i = 1; i <= n + 1; i++) {
        POW[i] = (POW[i-1] * 26) % MOD;
    }
    Hasha[0] = 0;
    for(ll i = 1; i <= n; i++) {
        Hasha[i] = (Hasha[i-1] * 26 + a[i] - 'a')%MOD; 
    }
    Hashb = 0;
    for(ll i = 1; i <= m; i++) {
        Hashb = (Hashb * 26 + b[i] - 'a')%MOD;
    }
    for(ll i = 1; i <= n-m+1; i++) {
        if(get_hasha(i, i+m-1) == Hashb)
            cout << i << " ";
    }
}

void init() {
    cin >> b;
    cin >> a;
}
#define task "SUBSTR"
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
