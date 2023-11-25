#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e5+10;
const ll MOD = 1e9+7;

ll n, k, a[N], b[N], s[N], flag = 1;

void sub2() {
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        flag = 1;
        for(int j = i; (j <= n && flag == 1) || (j < i && flag == 2); ((j == n && flag == 1) ? (j = 1, flag = 2) : j++)) {
            s[i] = (s[i] + (a[j] * b[j])%MOD)%MOD;
        }
    }
    for(int i = 1; i <= n; i++)
        cerr << s[i] << " ";
    cout << '\n';
    for(int i = 1; i <= n; i++) {
        s[i] += s[i-1];
        s[i] %= MOD;
    }
    cout << ((k/n * s[n])%MOD + s[k%n]%MOD)%MOD << '\n';
    for(int i = 1; i <= n; i++)
        cerr << s[i] << " ";
}

void solve() {
    sub2();
}

void init() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
}

#define task "a"
signed main() {
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
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}