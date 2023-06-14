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

const int MaxN = 1e5 + 10;
const ll MOD = 1e9 + 7;

bool is_prime(int x) {
    for(int i = 2; i * i <= x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}
//----------------------------
ll m, n, k, N;
string A, B;
bitset<MaxN> a[202];
vi ans;
//----------------------------
void solve() {
    A = ' ' + A;
    B = ' ' + B;
    for(int i = 1; i < A.size(); i++)
        if(A[i] != B[i]) {
            a[i][0] = 1;
        }
    for(int i = 1; i <= N; i++) {
        bool check = 0;
        for(int j = 1; j <= k; j++) {
            if(a[i][j]) {
                check = 1;
                for(int f = 1; f <= N; f++)
                    if(a[f][j] && f != i) {
                        a[f] ^= a[i];                        
                        //break;
                    }
                break;
            }
        }
        if(!check) {
            if(a[i][0]) {
                cout << -1;
                return;
            }
        } 
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= k; j++) {
            if(a[i][j] && a[i][0]){
                ans.eb(j);
                break;
            }
        }
    }
    if(ans.empty())
        cout << -1;
    else {
        cout << ans.size() << '\n';
        for(auto i : ans)
            cout << i << " ";
    }
}

void init() {
    cin >> m >> n >> k >> A >> B;
    N = m + n;
    for(int i = 1; i <= N; i++)
        a[i] = 0;
    for(int j = 1; j <= k; j++) {
            ll u, v;
            cin >> u >> v;
            a[u][j] = 1;
            a[m + v][j] = 1;
        }
}
//-----TASK----------
#define task ""
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
    solve();
}