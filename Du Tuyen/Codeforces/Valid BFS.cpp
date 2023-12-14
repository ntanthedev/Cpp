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

const int N = 5e5+10;
const ll MOD = 1e9+7;

int n, b[N], tt[N];
vi f[N], ans;
umib M;
bool cmp(int x, int y) {
    return tt[x] < tt[y];
}
queue<int> q;
void solve(){
    for(int i = 1; i <= n; i++) {
        sort(all(f[i]), cmp);
    }
    q.push(1);
    while(!q.empty()) {
        queue<int> temp;
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            ans.eb(x);
            M[x] = 1;
            for(auto j : f[x]) {
                if(!M[j])
                    temp.push(j);
            }
        }
        q = temp;
    }
    for(int i = 1; i <= n; i++) {
        if(b[i] != ans[i-1]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void init(){
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        f[u].eb(v);
        f[v].eb(u);
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        tt[b[i]] = i;
    }
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