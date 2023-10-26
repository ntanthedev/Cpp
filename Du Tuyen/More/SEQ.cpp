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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, a[N], l, r;
map<ll, ll> M;

void sub1() {
    ll res = 0;
    for(int i = 1; i <= l; i++)
        M[a[i]]++;
    for(int i = l+1; i <= n; i++)
        if(M[a[i]] == 0)
            res++;
        else 
            M[a[i]]--;
    cout << res << '\n'; 
}

void sub2() {
    ll res = 0, d = max(l, r) - min(l, r);

    if(l <= r) {
        for(int i = l+1; i <= n; i++) {
            M[a[i]]++;
            if(M[a[i]] > 1 && d > 0) {
                res++;
                d--;
                M[a[i]]--;
            }
        }
        for(int i = 1; i <= l; i++) {
            if(M[a[i]] == 0)
                res++;
            M[a[i]]--;
        }
        cout << res + d << '\n';
    }
    else {
        for(int i = 1; i <= l; i++) {
            M[a[i]]++;
            if(M[a[i]] > 1 && d > 0) {
                res++;
                d--;
                M[a[i]]--;
            }
        }
        for(int i = l+1; i <= n; i++) {
            if(M[a[i]] == 0)
                res++;
            M[a[i]]--;
        }
        cout << res + d << '\n';
    }

}

void solve() {
    if(l == r)
        sub1();
    else 
        sub2();
}

void init() {
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    M.clear();
}
#define task "SEQ"
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}