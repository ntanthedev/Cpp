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

ll n, a[N], s[N];


struct seg {
    ll sum, pre, suf;

    void build(int id, int l, int r) {
        if(l == r) {
            tree[id].sum = a[l];
            tree[id].pre = a[l];
            tree[id].suf = a[l];
        }
        else {
            int mid = (l + r) / 2;
            build(id*2, l, mid);
            build(id*2+1, mid+1, r);

        }
    }

    void combine(int id) {
        tree[id].sum = tree[id*2].sum + tree[id*2+1].sum;
        seg res;
    }
} tree[N];

void solve() {

}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
}

#define task "SubarraySumQueries"
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