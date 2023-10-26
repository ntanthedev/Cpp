#include <bits/stdc++.h>
#define fi first
#define se second

const long long N = 1e6 + 9;
using namespace std;

typedef long long ll;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

ll n, a[N], L, R;
pair<ll, ll> ans;

void solve() {
    sort(a + 1, a + 1 + n);
    ans.se = 0;
    if(L < a[1])
        ans.fi = L, ans.se = abs(a[1] - L);
    dbg(ans);
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i + 1])
            continue;
        if(a[i] >= R)
            break;
        if(a[i] < L && a[i + 1] >= L) {
            ll mid = (a[i] + a[i + 1]) / 2;
            if(L <= mid) {
                if(mid - a[i] >= ans.se)
                    ans.se = mid - a[i], ans.fi = mid;
            } else {
                if(a[i + 1] - L >= ans.se)
                    ans.se = a[i + 1] - L, ans.fi = L;
            }
        } else if(a[i] <= R && a[i + 1] > R) {
            ll mid = (a[i] + a[i + 1]) / 2;
            if(R >= mid) {
                if(mid - a[i] >= ans.se)
                    ans.se = mid - a[i], ans.fi = mid;
            } else {
                if(R - a[i] >= ans.se)
                    ans.se = R - a[i], ans.fi = R;
            }
        } else {
            ll mid = (a[i] + a[i + 1]) / 2;
            if(abs(mid + 1 - a[i + 1]) >= ans.se)
                ans.se = mid + 1 - a[i + 1], ans.fi = mid + 1;
        }
    }
    if(R > a[n])
        if(R - a[n] >= ans.se)
            ans.se = R - a[n], ans.fi = R;
    cout << ans.fi;
}

#define task "MAXDIS"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> L >> R;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
}