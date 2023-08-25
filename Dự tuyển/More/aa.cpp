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

ll n, m, temp, ans;

void solve() {
    m = sqrt(n);
    m = m * (m + 1) / 2;
 
    for (int i = 1; i <= sqrt(n); i++)
    {
        temp = n / i;
        ans += i * temp;
        ans %= MOD;
        temp %= MOD;
        temp = temp * (temp + 1) / 2 - m;
        temp %= MOD;
        ans += temp;
        ans %= MOD;
    }
    cout << ans;

}

void init() {
    cin >> n;
}

#define task "a"
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
// #include<bits/stdc++.h>
// //#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// //#pragma GCC target("sse4,avx2,fma")
// #define fi first
// #define se second
// #define mp make_pair
// #define pb push_back
// #define eb emplace_back
// #define all(x) x.begin(), x.end()

// using namespace std;

// typedef long long ll;
// typedef pair<int,int> ii;
// typedef pair<ll,ll> pll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef vector<ii> vii;
// typedef vector<vi> vvi;

// const int N = 1e5+10;
// const ll MOD = 1e9+7;

// int m, n;
// vi f[N];
// bool kk[N], vis[N];

// void dfs(int x, int co) {
//     for(auto i : f[x]) {
//         if(!vis[i] && co + (kk[i]) <= m)
//             dfs(i, co+1);     
//     }
// }

// void solve() {

// }

// void init() {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i++) {
//         int x;
//         cin >> x;
//         if(x)
//             kk[i] = true;
//         else 
//             kk[i] = false;
//         vis[n] = false;
//     }
//     for(int i = 1; i <= m; i++) {
//         int u, v;
//         cin >> u >> v;
//         f[u].eb(v);
//         f[v].eb(u);
//     }
// }

// #define task "aa"
// int32_t main() {
//     cin.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     if(fopen(task".inp","r")) {
//         freopen(task".inp","r",stdin);
//         freopen(task".out","w",stdout);
//     }
//     int test_case = 1;
//     //cin >> test_case;
//     while(test_case--) {
//         init();
//         solve();
//     }
// }
// /*
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long 
// #define ld long double
// #define pii pair<int,int>
// #define pll pair<ll,ll>
// #define F first
// #define S second
// const ll inf = 0x3f3f3f3f3f3f3f3f;
// const int T = 1e9 + 7;

// void read_file(string file, bool read = 1, bool write = 1) {
// 	string fileinp = file + ".INP", fileout = file + ".OUT";
// 	const char* INP = fileinp.c_str();
// 	const char* OUT = fileout.c_str();
// 	if(read) freopen(INP, "r", stdin);
// 	if(write) freopen(OUT, "w", stdout);
// }

// const int N = 1e3 + 5;
// string s;
// int n, ans = 0;
// ll dp[N][N];

// void Backtracking(int i, int d = 0, int max_d = 0) {
// 	if(i == n) {
// 		if(d == 0) {
// 			ans = max(ans, max_d);
// 			dp[i][d] = max(dp[i][d], (ll)max_d);
// 		}
// 		return ;
// 	}
// 	if(dp[i][d] != -1) return ;
// 	dp[i][d] = 0;
// 	if(s[i] ==  '(' || s[i] == '?') if(d <= n - i) {
// 		Backtracking(i + 1, d + 1, max(max_d, d + 1));
// 		dp[i][d] = max(dp[i][d], dp[i+1][d+1]);
// 	}
// 	if(s[i] == ')' || s[i] == '?') if(d > 0) {
// 		Backtracking(i + 1, d - 1, max(max_d, d - 1));
// 		dp[i][d] = max(dp[i][d], dp[i+1][d-1]);
// 	}
// }

// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);
// 	read_file("BTN1");
// 	memset(dp, -1, sizeof(dp));
// 	cin >> s;
// 	n = (int)s.size();
// 	Backtracking(0);
// 	cout << ans << "\n";
// 	return 0;
// }*/