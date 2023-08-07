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

ll n, x, S = 0, d = 0, h, k;
ll a[N], b[N];

void sub2() {
    for(int i = 1; i <= n; i++) {
        S += a[i] * b[i];
        if(a[i] >= b[i]) {
            if(2 * a[i] * b[i] + a[i] + b[i] >= 2 * h * k + k + h && a[i] * b[i] + a[i] >= h * k + h && a[i] * b[i] + a[i] >= k * h + k) {
                h = a[i], k = b[i];
            }
        } else {
            if(2 * a[i] * b[i] + a[i] + b[i] >= 2 * h * k + k + h && a[i] * b[i] + b[i] >= h * k + h && a[i] * b[i] + b[i] >= k * h + k) {
                h = a[i], k = b[i];
            }
        }
    }
    S -= h * k;
    ll m = h + k + x;
    if(h + x <= k)
        S += (h + x) * k;
    else if(k + x <= h)
        S += h * (k + x);
    else if(m % 2 == 0)
        S += m * m / 4;
    else
        S += (m / 2 + 1) * (m / 2);
    cout << S;
}

void sub1() {

}

void solve() {
    if(n <= 40)
        sub2();
    else 
        sub2();
}

void init() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    for(int i = 1; i <= n; i++) 
        cin >> b[i];
}
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("a.inp","r")) {
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}