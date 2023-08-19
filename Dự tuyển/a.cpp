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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll a, b, ans = 0;
vi vansongavl1 = {4, 7, 11, 308};
vi thanhminhcungga2 = {28, 77, 44};

void solve() {
    ll temp1 = 0, temp2 = 0;
    ans=0;
    // 4, 7, 11, 28, 44, 77, 308;
    // b -= b%4; aushit lmao
    // 1 .. . . . . .. . . .n
    // + 4 + 7 + 11 - 28 - 44 - 77 + 308
    //ơ dcm, hồi đó ac sao giờ ko ac ???`
    
    for(auto i: vansongavl1) {
        temp1 = (a % i == 0) ? a : (a+i-(a%i));
        temp2 = (b / i) * i;
        ans += (temp2 - temp1) / i + 1;
    }

    for(auto i: thanhminhcungga2) {
        temp1 = (a % i == 0) ? a : (a+i-(a%i));
        temp2 = (b / i) * i;
        ans -= (temp2 - temp1) / i + 1;
    }

    cout << ans << '\n';
}

void init() {
    cin >> a >> b;
}

#define task "a"
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case;
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}