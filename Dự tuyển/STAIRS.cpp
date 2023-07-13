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

string s;
ll dp[N];

inline bool check(char x) {
    if(x == '1')
        return true;
    return false;
}
void solve() {
    dp[0] = 0;
    dp[1] = check(s[1]) ? 1 : 0;
    dp[2] = check(s[2]) ? 2 : 0;
    dp[3] = check(s[3]) ? (dp[1] + dp[2] + 1) : 0;
    for(int i = 4; i < s.size(); i++) {
        if(!check(s[i])){
            dp[i] = 0;
            continue;
        }
        
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    if(!dp[s.size()-1])
        cout << "No";
    else 
        cout << "Yes\n" << dp[s.size()-1];
}

void init() {
    cin >> s;
    s = ' ' + s;
}
#define task "STAIRS"
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