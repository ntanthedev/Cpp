// Written by: ntannn_
// created in 15:19:59 - Sat 13/04/2024
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
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n, Q;
vector<bool> b, pre(N), suf(N);
vector<bool> op(1, 0);

void solve() {
    pre[0] = 0;
    pre[n / 2 + 1] = 0;
    for(int i = 1; i <= n / 2; i++) {
        if(op[i])
            if(i > 1)
                if(op[i - 1])
                    pre[i] = (b[i] & b[i - 1]) & pre[i - 2];
                else
                    pre[i] = (b[i] & b[i - 1]) | pre[i - 2];
            else 
                pre[i] = (b[i] & b[i - 1]);
        else 
            pre[i] = (b[i] | pre[i - 1]);
    }
    suf[n / 2] = 0;
    for(int i = n / 2 - 1; i >= 0; i--) {
        if(op[i + 1])
            if(i < n / 2 - 1)
                if(op[i + 2])
                    suf[i] = (b[i] & b[i + 1]) & suf[i + 2];
                else 
                    suf[i] = (b[i] & b[i + 1]) | suf[i + 2];
            else 
                suf[i] = b[i] & b[i + 1];
        else 
            suf[i] = (b[i] | suf[i + 1]);
    }
    
    cout << "\x1b[31mstart debug: \n";
    for(int i = 0; i <= n/2; i++)
        cout << pre[i]; cout << '\n';
    for(int i = 0; i <= n/2; i++)
        cout << suf[i]; cout << '\n';
    cout << "end of debug\e[39m \n";
    return;

    while(Q--) {
        int l, r; string s; 
        bool c = (s == "true");
        cin >> l >> r >> s;
        l >>= 1, r >>= 1;
        bool lef, rig, ans;
        lef = (l ? pre[l - 1] : 0);
        rig = (r == n / 2 ? 0 : suf[r + 1]);
        if(op[l]) 
            if(op[r + 1])
                ans = lef & 1 & rig;
            else 
                ans = lef & 1 | rig;        
        else 
            if(op[r + 1])
                ans = lef | 1 & rig;
            else 
                ans = lef | 1 | rig;
        if(ans == c) {
            cout << 1;
            continue;
        }
        if(op[l]) 
            if(op[r + 1])
                ans = lef & 0 & rig;
            else 
                ans = lef & 0 | rig;        
        else 
            if(op[r + 1])
                ans = lef | 0 & rig;
            else 
                ans = lef | 0 | rig;
        if(ans == c) 
            cout << 1;
        else 
            cout << 0;
    }
}

void init() {
    cin >> n >> Q;
    string s;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        if(s == "false")
            b.eb(0);
        else if(s == "true")
            b.eb(1);
        else if(s == "and")
            op.eb(1);
        else
            op.eb(0);
    }
    op.eb(0);
}

#define task "BOOL"
signed main() {
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
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}