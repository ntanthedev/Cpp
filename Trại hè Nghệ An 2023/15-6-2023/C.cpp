#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pf push_front
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

const int N = 2e5+10;
const ll MOD = 1e9+7;

ll n;
vi f[N];
deque<int> ans;
deque<int> dfs(int u){
    deque<int> left, right;
    deque<int> res;
    res.pf(1);
    if(f[u].size() == 0)
        return res;
    left = dfs(f[u][0]);
    if(f[u].size() != 1)
        right = dfs(f[u][1]);
    if(left.size() > right.size())
        swap(left, right);
    for(int i = 0; i < left.size(); i++)
        res.pb(left[i] + right[i]);
    if(left.size() < right.size())
        res.pb(right[left.size()]);
    return res;
}
void tienxuly(int x){
    for(int i: f[x]) {
        f[i].erase(find(f[i].begin(), f[i].end(), x));
        tienxuly(i);
    }
}
void solve(){
    ans = dfs(1);
    ll res = 0;
    for(int i = 0; i < ans.size(); i++)
        res += ans[i];    
    cout << n - res;
}

void init(){
    cin >> n;
    for(int i = 1; i < n; i++){
        ll u, v;
        cin >> u >> v;
        f[u].eb(v);
        f[v].eb(u);
    }
    tienxuly(1);
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