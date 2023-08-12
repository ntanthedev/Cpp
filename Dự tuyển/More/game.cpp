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

int Read() {
    bool neg = 1;
    char c = getchar();
    for(; c > '9' || c < '0'; c = getchar())
        if(c == '-')
            neg = !neg;
    int res = 0;
    while(c >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c - '0'), c = getchar();
    return neg ? res : -res;
}

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n, T, a[N], lmax[4 * N], lmin[4 * N];

void build(int id, int l, int r) {
    if(l == r) {
        lmax[id] = a[l];
        lmin[id] = a[r];
    } else {
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build((id << 1) + 1, mid + 1, r);
        lmax[id] = max(lmax[id << 1], lmax[(id << 1) + 1]);
        lmin[id] = min(lmin[id << 1], lmin[(id << 1) + 1]);
    }
}

int get_max(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return -1e9;
    if(d <= l && r <= c)
        return lmax[x];
    int mid = (l + r) >> 1;
    return max(get_max(x << 1, l, mid, d, c),
               get_max((x << 1) + 1, mid + 1, r, d, c));
}

int get_min(int x, int l, int r, int d, int c) {
    if(l > c || r < d)
        return 1e9;
    if(d <= l && r <= c)
        return lmin[x];
    int mid = (l + r) >> 1;
    return min(get_min(x << 1, l, mid, d, c),
               get_min((x << 1) + 1, mid + 1, r, d, c));
}

bool check(int k) {
    int l = 1, r = k;
    while(r <= n) {
        ll mmax = get_max(1, 1, n, l, r);
        ll mmin = get_min(1, 1, n, l, r);
        if(mmax - mmin <= T)
            return true;
        l++, r++;
    }
    return false;
}

void sub1() {
    build(1, 1, n);
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}

void dqmin(int k) {
    deque<int> dq;

    while(dq.size())
        dq.pop_front();

    for(int i = 1; i <= n; ++i) {
        while(dq.size() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        if(dq.front() + k <= i)
            dq.pop_front();
        if(i >= k)
            lmin[i] = a[dq.front()];
    }
}

void dqmax(int k) {
    deque<int> dq;

    while(dq.size())
        dq.pop_front();

    for(int i = 1; i <= n; ++i) {
        while(dq.size() && a[dq.back()] <= a[i])
            dq.pop_back();
        dq.push_back(i);
        if(dq.front() + k <= i)
            dq.pop_front();
        if(i >= k)
            lmax[i] = a[dq.front()];
    }
}

bool checksub2(int k) {
    dqmin(k);
    dqmax(k);
    for(int i = k; i <= n; i++) {
        if(lmax[i] - lmin[i] <= T)
            return true;
    }
    return false; 
}

void sub2() {
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(checksub2(mid)) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}

void solve() {
    if(n <= 1e5)
        sub2();
    else
        sub2();
}

void init() {
    n = Read(), T = Read();
    for(int i = 1; i <= n; i++)
        a[i] = Read();
}

#define task "game"
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