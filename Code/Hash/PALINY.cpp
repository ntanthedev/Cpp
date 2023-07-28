#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")


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

ll n, Pow[N], Hash[N], base = 311;
string s;

void make(ll x) {

}


void solve() {
    for(int i = 1; i <= n; i++) {
        Pow[i] = (Pow[i-1] * 26)%base;
    }
    for(int i = 1; i <= n; i++) {
        Hash[i] = (Hash[i-1] * 26 + (s[i] - 'a'))%base;
    }
    // chat le 
    ll l = 1, r = n;
    while(l < r) {
        int mid = (l+r)/2;
        
    }
}

void init() {
    cin >> n;
    cin >> s;
    s = ' ' + s;
}
#define task "PALINY"
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
        solve();
    }
}