// Written by: ntannn_
// created in 09:10:32 - Thu 01/08/2024
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

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

stack<int> st;
int n, k, a[N];
bool p[N];
string s;

void solve() {
    cin >> s >> k;
    n = s.size();
    for(int i = 1; i <= n; i++) {
        a[i] = s[i - 1] - '0';
    }
    for(int i = 1; i <= n; i++) {
        while(!st.empty() && k != 0) {
            if(a[st.top()] < a[i]) {
                p[st.top()] = 1;
                st.pop();
                k--;
            } else
                break;
        }
        st.push(i);
    }
    while(k--) {
        p[st.top()] = 1;
        st.pop();
    }
    for(int i = 1; i <= n; i++) {
        if(!p[i])
            cout << a[i];
    }
}

#define task "DELDIGIT"
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
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}