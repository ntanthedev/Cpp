#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
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

typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

//----------------------------
int m, n;
bool a[N][N];
bool visited[N][N];
//----------------------------
inline bool th1(int x, int y) {
    if(a[x][y + 2] && a[x + 1][y + 1] && a[x + 2][y] && a[x + 2][y + 2]) {
        visited[x][y + 2] = 1;
        visited[x + 1][y + 1] = 1;
        visited[x + 2][y] = 1;
        visited[x + 2][y + 2] = 1;
        return true;
    }
    return false;
}
inline bool th2(int x, int y) {
    if(a[x + 1][y - 1] && a[x + 1][y + 1] && a[x + 2][y]) {
        visited[x + 1][y - 1] = 1;
        visited[x + 1][y + 1] = 1;
        visited[x + 2][y] = 1;
        return true;
    }
    return false;
}
bool check(int x, int y) {
    if(visited[x][y])
        return true;
    if(x == 1 || x == m || y == 1 || y == n) {
        if(a[x][y + 2] && a[x + 1][y + 1] && a[x + 2][y] && a[x + 2][y + 2]) {
            visited[x][y + 2] = 1;
            visited[x + 1][y + 1] = 1;
            visited[x + 2][y] = 1;
            visited[x + 2][y + 2] = 1;
        }
        if(a[x + 1][y - 1] && a[x + 1][y + 1] && a[x + 2][y]) {
            visited[x + 1][y - 1] = 1;
            visited[x + 1][y + 1] = 1;
            visited[x + 2][y] = 1;
        }
        visited[x][y] = true;
        return true;
    }
    if(th1(x, y))
        return true;
    if(th2(x, y))
        return true;
    return false;
}
void solve() {
    for(int i = 0; i <= n + 1; i++)
        visited[0][i] = 1, visited[m + 1][i] = 1, a[0][i] = 1, a[m + 1][i] = 1;
    for(int i = 0; i <= m + 1; i++)
        visited[i][0] = 1, visited[i][n + 1] = 1, a[i][0] = 1, a[i][n + 1] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j])
                if(!check(i, j)) {
                    cout << "NO\n";
                    return;
                }
        }
    }
    cout << "YES\n";
}
void init() {
    while(cin >> m >> n) {
        char c;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++) {
                cin >> c;
                if(c == '*')
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
                visited[i][j] = 0;
            }
        solve();
        // for(int i = 1; i <= m; i++){
        //     for(int j = 1; j <= n; j++){
        //         if(visited[i][j])
        //             cout << 1 << " " ;
        //         else
        //             cout << 0 << " " ;
        //     }
        //     cout << '\n';
        // }
    }
}
//-----TASK----------
#define task "RCOLOR"
//-------------------
int32_t main() {
    //---------------------------------
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    //---------------------------------
    init();
    //    solve();
}
