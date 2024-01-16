#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

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
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, od[N], k, ev[N], ans = 0;
map<ll, ll> M;
queue<int> q;

void solve() {
    q.push(0); q.push(1);   
    for(int i = 2; i <= n; i++) {
        int l = lower_bound(ev + 1, ev + 1 + i, ev[i]) - ev - 1,
            r = lower_bound(od + 1, od + 1 + i, od[i]) - od - 1;
        int t = min(l, r);
        while(!q.empty() && q.front() <= t) {
            int j = q.front();
            M[ev[j] - od[j]]++;
            q.pop();
        }
        for(int j = 0; j <= k; j++) {
            map<ll, ll>::iterator it = M.find(ev[i] - od[i] - j);
            if(it != M.end())
                ans += it->se;
        }
        q.push(i);
    }
    cout << ans;
}

void init() {
    read(n), read(k);
    od[0] = 0;
    ev[0] = 0;
    for(int i = 1, x; i <= n; i++) {
        read(x);
        od[i] = od[i-1] + (x & 1)*x;
        ev[i] = ev[i-1] + (x%2 == 0)*x;
    }
    // for(int i = 1; i <= n; i++) cout << od[i] << " "; cout << '\n';
    // for(int i = 1; i <= n; i++) cout << ev[i] << " " ; cout << '\n';
}

#define task "DAYSODEP"
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
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}