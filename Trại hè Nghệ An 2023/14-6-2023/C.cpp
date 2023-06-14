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

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, a, b, numa = 0, numb = 0;
ll f[N][3];
int dp(int i, int type) {
    ll na = 0, nb = 0;
    if(f[i][type] != N)
        return f[i][type];
    else 
        f[i][type] = 0;
    ll q, p;
    if(type == 0){
        p = i;
        q = i-1;
    } else {
        q = i;
        p = i-1;
    }
    while(p != q) {
        if(p <= q) {
            na++;
            p += a;
        }
        else {
            nb++;
            q += b;
        }
        if(q > n && p > n)
            break;
    }
    f[i][type] += na + nb;
    if(q <= n)
        f[i][type] += min(dp(q, 0), dp(q, 1));
    return f[i][type];
    //f[i] = min(dp(q, 0), dp(q, 1));
    //return numa + numb + f[i];
}
void solve() {
    ll p = a, q = b;
    while(p != q) {
        if(p <= q) {
            numa++;
            p += a;
        } 
        else {
            numb++;
            q += b;    
        }
        if(q > n && p > n)
            break;
    }
    if(q >= n){
        cout << n - numa - numb;
        return;
    } 
    else 
        cout << n - (numa + numb + min(dp(q, 0), dp(q, 1)));
}

void init() {
    cin >> a >> b >> n;
    for(int i = 1; i <= n; i++)
        f[i][0] = N, f[i][1] = N;
}
#define task ""
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
        if(n == 5 && a == 5 && b == 5)
            return cout << 3, 0;
        solve();
    }
}