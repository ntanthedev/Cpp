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

ll n;
vector<char> vt;
void solve() {
    while(n != 0) {
        if(n % 16 < 10) vt.eb(char(n%16 + '0'));
        if(n % 16 == 10) vt.eb('A');
        if(n % 16 == 11) vt.eb('B');
        if(n % 16 == 12) vt.eb('C');
        if(n % 16 == 13) vt.eb('D');
        if(n % 16 == 14) vt.eb('E');
        if(n % 16 == 15) vt.eb('F');
        n /= 16;
    }
    reverse(all(vt));
    for(int i = 0; i < vt.size(); i++)
        cout << vt[i];
}

void init() {
    cin >> n;
}
int32_t main() {
    #define task "HEXA"
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