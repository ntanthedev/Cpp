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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, m, a[N], f[N], pos = 0;
ll M[N];
void sub1() {
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++) {
            if(i==j) continue;
            f[a[i] + a[j]]++;
            //cout << a[i] << " " << a[j] << '\n';
        }
    ll res = 0;
    for(int i = 1; i <= m; i++)
        res += f[i];
    cout << res << '\n';
}
void solve() {
    sort(a+1, a+1+n);
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        ll t = upper_bound(a+1, a+1+n, m - a[i]) - a - 1;
        res += t;
    }
    cout << res << '\n';
}   

void init() {
    memset(f, 0, sizeof(f));
    memset(M, 0, sizeof(M));
    read(n), read(m);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
        M[a[i]]++;
    }
}
#define task "FM"
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
        //if(n <= 5*1e3)
            sub1();
        //else 
            //solve();
    }
}