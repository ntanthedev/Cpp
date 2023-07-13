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

ll ans = 0, n, a[N], d, pos = INT_MIN;
bool M[N];
struct pt {
    ll lef, rig, sz, be, ed;
};
pt b[N];
void solve() {
    pos = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if(!M[i]) {
            b[i].sz = 0;
            continue;
        }
        if(M[i-1]) {
            b[i].lef = b[i-1].lef;
            b[i].be = b[i-1].be;
            b[i].sz = b[i-1].sz+1;
        }
        else {
            b[i].lef = i - pos - 1;
            b[i].be = i;
            b[i].sz = 1;
            //cout << i << " " << b[i].lef << '\n'; 
        }
        pos = i;
    }
    pos = INT_MAX;
    for(int i = n; i >= 1; i--) {
        if(!M[i]) 
            continue;
        if(M[i+1]) {
            b[i].rig = b[i+1].rig;
            b[i].ed = b[i+1].ed;
            b[i].sz = b[i+1].sz;
        }
        else {
            b[i].rig = abs(i - pos) - 1;
            b[i].ed = i;
            //cout << i << " " << b[i].rig << '\n';
        }
        pos = i;
    }
    b[0].sz = 0;
    b[n+1].sz = 0;
    for(int i = 1; i <= n; i++) {
        if(!M[i]) continue;
        if(d >= b[i].lef) 
            ans = max(ans, b[i].sz + b[b[i].be-b[i].lef-1].sz);
        if(d >= b[i].rig)
            ans = max(ans, b[i].sz + b[b[i].ed + b[i].rig + 1].sz);
        if(d >= b[i].lef + b[i].rig) 
            ans = max(ans, b[i].sz + b[b[i].be-b[i].lef-1].sz + b[b[i].ed + b[i].rig + 1].sz);
        //cout << ans << " " << b[i].be-b[i].lef-1 << " " << b[i].ed + b[i].rig + 1 << '\n';
    }
    cout << ans ;
}

void init() {
    read(n);
    memset(M, false, sizeof(M));
    for(int i = 1; i <= n; i++){
        read(a[i]);
        pos = max(pos, a[i]);
        if(!a[i])
            d++;
        if(a[i] != 0)
            M[a[i]] = 1;
    }
    n = pos;
}
#define task "LSEQ"
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
/*
sort(a+1, a+1+n);
    ll l = -1, r = -1;
    for(int i = 2; i <= n; i++) {
        if(a[i] - a[i-1] == 1) {
            if(l == -1)
                l = i-1;
            r = i;
        }
        else {
            if(l == -1) continue;
            t = mp(l, r);
            b.pb(t);
            l = -1;
            r = l;
        }
    }
*/