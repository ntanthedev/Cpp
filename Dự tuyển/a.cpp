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
const ll MOD = 1e9+7;

ll n, a[30];
vii ans;
bool flag;

void solve() {
    ans.clear();
    if(!flag) {
        cout << 0 << '\n';
        return;
    }
    ll gmax;
    for(int i = 1; i <= n; i++)
        if(a[i] > a[gmax])
            gmax = i;
    if(a[gmax] < 0) {//xu ly tim gmin
        for(int i = 1; i <= n; i++)
            if(a[i] < a[gmax])
                gmax = i;
        for(int i = n; i >= 2; i--) {
            if(a[i] < a[i-1]) {
                a[i-1] += a[i];
                ans.pb(mp(i-1, i));
            }
        }
    }
    else {
        
    }
    //cout << "----------------\n";
    cout << ans.size() << '\n';
    for(auto i : ans) {
        cout << i.fi << " " << i.se << '\n';
    }
}

void init() {
    flag = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] < a[i-1])
            flag = 1;
    }
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
    a[0] = LLONG_MIN;
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}