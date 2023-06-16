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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

int b[N], c[N];
ll n, f[N];
vi a;
void solve(){
    a.eb(0);
    a.eb(1);
    a.eb(2);
    a.eb(2); b[2] = 1;
    ll i = 3;
    while(i <= n && a.size() <= 1e6){
        for(int j = 1; j <= a[i]; j++)
            a.eb(i);
        i++;
    }
    f[0] = 0;
    for( i = 1; i <= 1e6; i++){
        b[i] = a[i]*i;
        f[i] = f[i-1] + b[i];
    }
    c[1] = 1;
    for( i = 2; i <= 1e6; i++){
        c[i] = c[i-1] + a[i];
    }
    for(i = 1; i <= 1e6; i++){
        if(f[i] >= n)
            break;
    }
    ll ans = (n - f[i-1] - 1)/i + 1 + c[i-1];
    cout << ans;
}

void init(){
    cin >> n;
    a.reserve(N);
}
#define task ""
int32_t main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--){
        init();
        solve();
    }
}