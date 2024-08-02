<<<<<<< HEAD
//Written by: ntannn_
//created in 19:17:02 - Thu 01/08/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 1e3 + 10;
const ll MOD = 1e9 + 7;

int n, k, s = 0;
int c[N];
map<int, vi> m;

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> c[i];
        s += c[i];
    }

    m[0] = {0};
    for(int i = 1; i <= n; i++) {
        for(int j = s; j >= c[i]; j--) {
            if(m.find(j - c[i]) != m.end()) {
                merge(all(m[j - c[i]]), all(m[j]), m[j]);
                m[j].pb(c[i]);
            }
        }
    }

    s = 0;
    for(auto i : m[k])
        s += i;
    
    vector<bool> p(1000001, false);
    p[0] = 1;
    for(auto i : m[k]) {
        for(int j = s; j >= i; j--) {
            if(!p[j] && p[j - i])
                p[j] = 1;
        }
    }

    for(int i = 0; i <= 1000001; i++) {
        if(p[i])
            cout << i << " ";
    }
}

#define task "a"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
=======
//problem "a"
//created in 09:39:54 - Fri 02/08/2024

#include<bits/stdc++.h>

using namespace std;

int n;
string s;

struct pt {
    int val, pre, suf, ans;
};

inline void make(pt &x) {

}

void build() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s;
    n = s.size();
    s = ' ' + s;
}
/*
    ())(())(())(
d:  100121012100

*/

/*
( ())
*/
>>>>>>> c7e76b725856ffdaf47cdbebfbc87e10154cfe18
