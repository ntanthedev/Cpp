#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
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

ll n, m, k, t, a[N][N];
ll s[N][N];

ll get_sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

void sub2() {
    ll ans = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            ll res = 0;
            for(ll f = 0; f <= min(n - j, m - i); f++)
                if(get_sum(i, j, i+f, j+f) <= t)
                    res = max(res, (f+1)*(f+1));
                else 
                    break;
            ans = max(ans, res);
        }
    }
    cout << ans;
} 


void sub3() {
    ll ans = 0;
    for(int x1 = 1; x1 <= m; x1++) {
        for(int y1 = 1; y1 <= n; y1++) { 
            
            for(int x2 = x1; x2 <= m; x2++) {
                for(int y2 = y1+2; y2 <= n; y2++) {

                    ll res = 0;    
                    for(ll f = 0; ((y1 + f < y2 && x1 + f >= x2) || (y1 + f >= y2 && x1 + f < x2)) && f <= min(m - x2, n - y2); f++) {
                        for(ll g = 0; g <= min(m - x2, n - y2); g++) {
                            if(get_sum(x1, y1, x1+f, y1+f) + get_sum(x2, y2, x2+g, y2+g) <= t) {
                                res = max(res, (f+1)*(f+1) + (g+1)*(g+1));
                            }
                            else 
                                break;
                        }
                    }
                    ans = max(ans, res);
                }
            }
        }
    }
    cout << ans ;
}

void solve() {
    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }

    if(k == 1)
        sub2();
    else 
        sub3();    
}

void init() {
    read(m), read(n), read(k), read(t);
    for(int i = 1; i <= m; ++i)  
        for(int j = 1; j <= n; ++j)  
            read(a[i][j]);
    memset(s, 0, sizeof(s));
}

#define task "VILLA"
signed main() {
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