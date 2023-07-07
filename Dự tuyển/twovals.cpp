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

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, a[N], ans = 0;
map<ll, ll> M;
ii s1, s2;
void solve() {
    s1 = mp(1, 1);
    s2 = s1;
    ll l = 1, r = 2, d = 1;
    while(r <= n) {
        if(a[r] != s1.fi && s2.fi)
            d++;
        while(d > 2) {
            if(a[l] == s1.fi)
                s1.se--;
            if(!s1.se)
                d--;
            if(a[l] == s2.fi)
                s2.se--;
            if(!s2.se)
                d--;
            l++;
        }
        s1 = s2;
        s2.fi = a[r];
        s2.se++;
        if(d == 2)
            ans = max(ans, r - l + 1);
        cout << l << " " << r << " " << d << " " << ans << '\n';
        r++;
    }
    cout << ans ;
}

void init() {
    read(n);
    for(int i = 1; i <= n; i++) {
        read(a[i]);
    }
}
#define task "twovals"
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