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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, S, a[N], s[N];
vll ans;
bool flag = 0;

void solve(int i = 1, ll res = 0) {
    if(flag)
        return;
    if(i > n) {
        if(res == S) {
            cout << "YES\n";
            for(auto j : ans)
                cout << j << " " ;
            flag = 1;
        }
    }
    for(int j = 0; j <= 1; j++) {
        if(res + a[i]*j > S || res + (s[n] - s[i-1]) < S)
            continue;
        if(j)
            ans.pb(i);
        solve(i+1, res + a[i]*j);
        if(j)
            ans.pop_back();
    }
}

void init() {
    cin >> n >> S;
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
}

#define task "SUBSETSUM"
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
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}