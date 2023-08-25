#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define mask(j) (1<<j)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e3+10;
const ll MOD = 1e9+7;

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

ll m, n, a[N][N];
string c;
ll dp[N][N];

void solve() {
    for(int i = 1; i <= n; i++) 
        dp[1][i] = a[1][i];
    for(int i = 2; i <= m; i++) {
        dp[i][0] = 0;
        dp[i][n+1] = 0; 
        for(int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i-1][j+1])) * a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dp[m][i]);
    stack<int> st;
    while(ans > 0) {
        st.push(ans%2);
        ans /= 2;
    }
    //cout << st.size()<< '\n';
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c;
            reverse(all(c));
            ll num = 0;
            for(int j = 0; j < c.size(); j++) {
                if(c[j] == '1')
                    num += mask(j);
            }
            a[i][j] = num;
        }
    }
}

#define task "BAI2"
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