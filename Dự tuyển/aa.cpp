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
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;


string a, b, c;
ll n, k;
void solve() {
    a = 'a';
    b = 'b';
    if(n == 0) c = a; //return;}
    if(n == 1) c = b;// return;}
    for(int i = 2; i <= n; i++) {
        c = b + a;
        a = b;
        b = c;
    }
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        if(c[i] == 'a')
            ans++;
    }
    cout << ans << '\n';
}

void init() {
    cin >> n >> k;
}
#define task ""
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case = 1;
    cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
}