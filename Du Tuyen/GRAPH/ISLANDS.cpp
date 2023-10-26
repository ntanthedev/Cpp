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


typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e3+10;
const ll MOD = 1e9+7;

int ans = 0, m, n, a[N][N], k, res = 0;
int par[1000009];
vii days[1000009];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool check(int x, int y) {
    if(x < 1 || x > m || y < 1 || y > n)
        return false;
    return true;
}

inline int get_id(int x, int y) {
    return (x-1)*n + y;
}

int find_set(int x) {
    return par[x] < 0 ? x : par[x] = find_set(par[x]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if(a != b) {
        if(par[a] > par[b])
            swap(a, b);
        par[a] += par[b];
        par[b] = a;
        res--;
    }
}

void solve() {
    memset(par, 0, sizeof(par));
    for(int i = k; i >= 0; i--) {
        if(days[i].empty()) continue;
        for(auto j : days[i]) {
            par[get_id(j.fi, j.se)] = -1;
            // if(i == 4)
                //cout << "d4: " << res << " ";
            res++;
            // if(i == 4)
            //     cout << res << " ";
            for(int f = 0; f < 4; f++) {
                int nx = j.fi + dx[f];
                int ny = j.se + dy[f];
                if(!check(nx, ny))
                    continue;
                if(par[get_id(nx, ny)] != 0) {
                    // if(i == 4)
                    //     cout << j.fi << " " << j.se << " " << nx << " " << ny << " " << res << ' ';
                    union_sets(get_id(nx, ny), get_id(j.fi, j.se));
                }
            }
            // if(i == 4)
            //     cout << res << '\n' ;
        }
        ans = max(ans, res);
        // cout << i << " " << res << ' ';
        // for(auto j : days[i])
        //     cout << j.fi << "-" << j.se << " " ;
        // cout << '\n'; 
    }
    cout << ans;
}

void init() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            days[a[i][j]-1].eb(mp(i, j));
            k = max(k, a[i][j]);
        }
}
#define task "ISLANDS"
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