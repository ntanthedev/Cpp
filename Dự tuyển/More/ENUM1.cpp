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

const int N = 1e3+10;
const ll MOD = 1e9+7;

ll n, f[N][N];

ll solve(int i, int d) {
    if(i > n) {
        if(d == 0)
            return 1;
    }
    if(f[i][d] != -1) 
        return f[i][d]%MOD;
    f[i][d] = 0;
    if(d+1 <= n-i) 
        f[i][d] += solve(i+1, d+1)%MOD;
    if(d > 0)
        f[i][d] += solve(i+1, d-1)%MOD;
    return f[i][d]%MOD;

}

void init() {
    cin >> n;
    if(n%2 != 0) {
        cout << 0;
        return;
    }
    memset(f, -1, sizeof(f));
    cout << solve(1, 0)%MOD;
}

#define task "ENUM1"
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
    }
}