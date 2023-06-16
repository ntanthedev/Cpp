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

const int N = 2e5+10;
const ll MOD = 1e9+7;

int m, n, fre = 0, a[N];
vi ans, cnt[N], v[N], b[N];
bool M[N];
queue<int> q;
void solve(){ 
    for(int i = 1; i <= n; i++) {
        for(int j = a[i]; j <= 2e5; j += a[i]) {
            v[j].pb(a[i]);
        }
    }
    for(int i = 1; i <= N; i++) {
        // if(!b[i].empty() && v[i].empty()) {
        //     for(auto j : b[i]){
        //         q.push(j);
        //         b[i].pop_back();
        //     }
        //     //continue;
        // }
        if(!b[i].empty()) {
            for(auto j : b[i]) {
                q.push(j);
                b[i].pop_back();
            }
            for(auto j : v[i]) {
                if(!M[j] && q.empty()) {
                    fre++;
                    M[j] = 1;
                }
                if(!M[j]) {
                    ans.eb(i);
                    M[j] = 1;
                    q.pop();
                }
            }
        }        
        if(!q.empty()) {
            while(fre && !q.empty()) {
                ans.eb(i);
                fre--;
                q.pop();
            }
            if(!q.empty())
                for(auto j : v[i]) {
                    if(!M[j]){
                        q.pop();
                        ans.eb(j);
                        M[j] = 1;
                    }
                }
        }
    }
    for(auto i : ans)
        cout << i << " ";
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++){
        int x;
        cin >> x;
        b[x].eb(i);
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