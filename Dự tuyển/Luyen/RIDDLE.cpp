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

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

int m, n, a[21], b[N];
int x[21];
map<ll, int> M;
string s;

void check() {
    ll res = 0;
    for(int i = 1; i <= m; i++) {
        if(x[i])
            res += a[i];
    }
    if(M[res] != 0)
        s[M[res]-1] = '1';
}

void backtracking(int i) {
    for(int j = 0; j <= 1; j++) {
        x[i] = j;
        if(i == m)
            check();
        else 
            backtracking(i+1);
    }
}

void solve() {
    s.resize(n, '0');
    backtracking(1);
    
    cout << s;
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        M[b[i]] = i;
    }
}

#define task "RIDDLE"
signed main() {
    cin.tie(nullptr);
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