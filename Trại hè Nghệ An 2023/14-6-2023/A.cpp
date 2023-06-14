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

const int N = 1e3+10;
const ll MOD = 1e9+7;
ll dx[] = {1, -1, 0, 0, -1, -1, 1, 1}; 
ll dy[] = {0, 0, 1, -1, -1, 1, 1, -1};
ll m, n;
ll maxx = -1, maxy = -1, minx = N, miny = N;
ii a[N];
vll f;
ll visited[N];
queue<ii> q;
bool check(){
    if(maxx == n && (minx == 1 || maxy == n)){
        //cout << 111 << '\n';
        return true;
    }
    if(minx == 1 && (miny == 1)){
        //cout << 113 << '\n';
        return true;
    }
    if(maxy == n && miny == 1)
        return true;
    return false;
}
void bfs(int x){
    q.push(a[x]);
    visited[x] = 1;
    while(!q.empty()){
        ii u = q.front(); q.pop();
        for(int i = 1; i <= m; i++){
            for(int j = 0; j < 8; j++)
                if(!visited[i] && (u.fi + dx[j] == a[i].fi) && (u.se + dy[j] == a[i].se)){
                    q.push(a[i]);
                    visited[i] = 1;
                }
        }
        maxx = max(maxx, ll(u.fi));
        maxy = max(maxy, ll(u.se));
        minx = min(minx, ll(u.fi));
        miny = min(miny, ll(u.se));
        //cout << u.fi << " " << u.se << '\n';
    }
}
void solve(){
    //cout << "--------------\n";
    for(int i = 1; i <= m; i++){
        if(!visited[i]){
            maxx = -1, maxy = -1, minx = N, miny = N;
            bfs(i);
            if(check()){
                cout << "NO";
                return;
            }
        }
    }
    //cout << maxx << " " << maxy << " " << minx << " " << miny << '\n'; 
    cout << "YES";
}

void init(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> a[i].fi >> a[i].se;
        visited[i] = 0;
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