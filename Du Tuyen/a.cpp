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

ll n, res = 1;
string x, y, z;
map<string, ll> M;

void solve() {
    for(int i = 0; i < x.size(); i++)
        x[i] = tolower(x[i]);
    for(int i = 0; i < z.size(); i++)
        z[i] = tolower(z[i]);
    int temp = M[z] + 1;
    if(temp > res)
        res = temp;
    M[x] = temp;
}

void init() {

}

#define task "a"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    cin >> test_case;
    while(test_case--) {
    M["polycarp"] = 1;
        init();
        solve();
    }
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int n, ans = 1;
    string a, b, c;
    map<string, int> l;
    l["polycarp"] = 1;
    cin >> n;
    while(n--) {
        
    }
    cout << ans;
    return 0;
}