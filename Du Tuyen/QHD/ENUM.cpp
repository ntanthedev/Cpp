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

ll n, x[26];

bool check() {
    int d = 0;
    for(int i = 1; i <= n; i++) {
        if(x[i])
            d--;
        else 
            d++;
        if(d < 0)
            return false;
    }
    if(d != 0)
        return false;
    return true;
}

void out() {
    if(check()) {
        for(int i = 1; i <= n; i++) {
            if(x[i])
                cout << ")";
            else 
                cout << "(";
        }
        cout << '\n';
    }
}

void solve(int i) {
    for(int j = 0; j <= 1; j++) {
        x[i] = j;
        if(i == n)
            out();
        else 
            solve(i+1);
    }
}

void init() {
    cin >> n;
    solve(1);
}

#define task "ENUM"
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
        //solve();
    }
}