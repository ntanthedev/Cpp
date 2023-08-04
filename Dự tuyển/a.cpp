#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()

using namespace std;

template<typename T>
inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n, a[101], ans = 0;

void solve() {
    for(int i = 1; i <= n; i++) {
        while(a[i] != 0) {
            int tmp = a[i];
            for(int j = i + 1; j <= n; j++) {
                if(a[j] == 0)
                    break;
                tmp = min(tmp, a[j]);
            }
            ans += tmp;
            for(int j = i; j <= n; j++) {
                if(a[j] == 0)
                    break;
                a[j] -= tmp;
            }
        }
    }
    cout << ans;
}

void init() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
}
#define task ""
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    // cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}