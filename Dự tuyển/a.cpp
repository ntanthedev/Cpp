#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
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
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

string a, b;
string sumstring(string x, string y) {
    if(x > y)
        swap(x, y);
    string res;
    res.resize(y.size());
    int nho = 0, t;
    while(x.size() < y.size()) 
        x = "0" + x;
    for(int i = x.size()-1; i >= 0; i--) {
        t = (x[i] - '0') + (y[i] - '0') + nho;
        if(t >= 10) 
            nho = 1;
        else 
            nho = 0;
        t %= 10;        
        res[i] = char(t + '0');
    }
    if(nho) 
        res = "1" + res;
    return res;
}
string productstring(string x, string y) {
    string c = "", res = "0";
    ll pos = 0;
    if(x > y)
        swap(x, y);
    for(int i = x.size()-1; i >= 0; i--) {
        ll t = 0, nho = 0;
        c = "";
        for(int j = y.size()-1; j >= 0; j--) {
            t = (x[i] - '0')*(y[j] - '0') + nho;
            nho = t/10;
            t %= 10;
            c = char(t + '0') + c;
        }
        if(nho)
            c = char(nho + '0') + c;
        for(int j = 1; j <= pos; j++)
            c = c + "0";
        res = sumstring(c, res);
        pos++;
    }
    return res;
}
void solve() {
    cout << productstring(a, b);
}

void init() {
    cin >> a >> b;
}
#define task ""
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