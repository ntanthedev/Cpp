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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

string a, b;
ll n, f[20][2][2][2];

ll cal(int i, bool oka, bool okb, bool pre) {
    if(i >= n)
        return 1;
    if(f[i][oka][okb][pre] != -1)
        return f[i][oka][okb][pre];
    f[i][oka][okb][pre] = 0;
    for(int j = '0'; j <= '9'; j++) {
        if((j >= a[i] || oka) && (j <= b[i] || okb) && (j != '3' || !pre))
            f[i][oka][okb][pre] += cal(i + 1, oka || j > a[i], okb || j < b[i], j == '1');
    }
    return f[i][oka][okb][pre];
}

void solve() {
    n = b.size();
    while(a.size() != b.size())
        a = '0' + a;
    cout << cal(0, false, false, false) << '\n';
}

#define task "N13"
int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    while(cin >> a >> b) {
        memset(f, -1, sizeof(f));
        solve();
    }
}