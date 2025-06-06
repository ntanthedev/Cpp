#include <bits/stdc++.h>
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
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

int n, s[N], k, m, nex[N], check[N], L[N];

struct pt {
    int i, j, c;
};

string ss;

vector<pt> q;

string xuat(string s, int k) {
    string s1;
    for(int i = 0; i < s.size(); i++) {
        while(s1.size() > 0 && k > 0 && s[i] > s1.back()) {
            k--;
            s1.pop_back();
        }
        s1.push_back(s[i]);
    }
    return s1.substr(0, s1.length() - k);
}

int Find(int i) {
    if(check[nex[i]] == -1)
        return nex[i] = Find(nex[i]);
    else
        return nex[i];
}

void Fill(int i, int j, int c) {
    for(int f = Find(i - 1); f <= j; f = Find(f)) {
        s[f] = c;
        check[f] = -1;
    }
}

void solve() {
    reverse(all(q));
    for(auto i: q) {
        Fill(i.i, i.j, i.c);
    }
    for(int i = 1; i <= n; i++) {
        if(s[i] == -1)
            ss.push_back('1');
        else 
            ss.push_back(char(s[i] + 48));
    }
    cout << xuat(ss, k);
}

void init() {
    cin >> n >> m >> k;
    memset(s, -1, sizeof(s));
    while(m--) {
        pt x;
        cin >> x.i >> x.j >> x.c;
        q.pb(x);
    }
    for(int i = 0; i <= n; i++)
        nex[i] = i + 1;
}
#define task "FILLCHAR"
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