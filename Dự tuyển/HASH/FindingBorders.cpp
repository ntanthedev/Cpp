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
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+3;

ll H[N], POW[N], base = 311, n;
string s;

ll get_hash(int i, int j) {
    return (H[j] - H[i-1] * POW[j-i+1] + MOD * MOD) % MOD;
}

void solve() {
    n = s.size();
    s = ' ' + s;
    POW[0] = 1;
    H[0] = 0; 
    for(int i = 1; i <= n; i++) {
        POW[i] = (POW[i-1] * base)%MOD;
    }
    for(int i = 1; i <= n; i++) {
        H[i] = (H[i-1] * base + s[i] - 'a' + 1) % MOD;
    }

    for(int i = 1; i < n; i++) {
        ll a = get_hash(1, i), b = get_hash(n-i+1, n);
        if(a == b)
            cout << i << " ";
    }
}

void init() {
    cin >> s;
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