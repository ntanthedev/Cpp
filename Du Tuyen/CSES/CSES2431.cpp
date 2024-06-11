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

ll poww(int i) {
    ll s = 1;
    for(int j = 1; j <= i; j++) 
        s *= 10;
}

ll k;
ll a[19];

void solve() {
    ll t = upper_bound(a + 1, a + 19, k) - a - 1;
    ll s = k - a[t], temp;
    temp = s%t;

}

void init() {
    cin >> k;
}

#define task "DigitQueries"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    a[0] = 0;

    for(int i = 1; i <= 18; i++) {
        a[i] = i * 9 * poww(i-1) + a[i-1];
    }

    int test_case = 1;
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}

// 9 * 10^(i-1) * i