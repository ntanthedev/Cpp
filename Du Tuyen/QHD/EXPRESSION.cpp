#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, S, a[N], s[N];
bool flag = 0;
string ans;

void dynamic_programing() {

}

void solve(int i = 2, ll res = a[1]) {
    if(flag)
        return;
    if(i > n) {
        if(res == S) {
            cout << ans;
            flag = 1;
        }
    }
    for(int j = -1; j <= 1; j += 2) {
        if(res + a[i]*j - (s[n] - s[i]) > S || res + j*a[i] + (s[n] - s[i]) < S)
            continue;
        ans.pb((j == -1 ? '-' : '+'));
        solve(i+1, res + j*a[i]);
        ans.pop_back();
    }
}

void init() {
    cin >> n >> S;
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
}

#define task "EXPRESSION"
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
/*
//Written by: Jethro_
//----------------------
#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int n, m, a[N], sum = 0, dp[10000009];
bool mark[N];

void ReadInput() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }    
}
void solve() {
    sum -= m;
    sum /= 2;
    vector<vector<int>> res(sum + 1);
    dp[0] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = sum; j >= a[i]; --j) {
            if (dp[j - a[i]]) {
                dp[j] += dp[j - a[i]];
                res[j] = res[j - a[i]];
                res[j].push_back(i);
            }
        }
    }
    for (auto it : res[sum]) {
        mark[it] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        if (mark[i]) cout << "-";
        else cout << "+";
    }
}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("EXPRESSION.inp", "r", stdin);
    freopen("EXPRESSION.out", "w", stdout);
    ReadInput();
    solve();

}

// 8 - 7  - 4  + 3  + 5

// //8 3 5
// 16 
// 26
// 10



// 8 - 7 + 9 + 7 + 4  - 3


// 18

// 38 

// 20
*/