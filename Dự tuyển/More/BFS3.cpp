#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
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

typedef long double ld;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
typedef vector<ii> vii;
typedef unordered_map<int, int> umii;
typedef unordered_map<int, bool> umib;
typedef unordered_map<ll, ll> umll;

const int N = 1e6+10;
const ll MOD = 1e9+7;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------
int  m, n, be, ed;
vii f[N];
vi ans;
umib M;
ii trace[N];
queue<ii> q;
//----------------------------
void solve(){
    for(int i = 1; i <= n; i++)
        sort(all(f[i]));
    q.push(make_pair(be, -1));
    M[be] = 1;
    while(!q.empty()){
        for(auto v : f[q.front().fi]){
            if(!M[v.fi]){
                M[v.fi] = 1;
                trace[v.fi] = q.front();
                if(v.fi == ed){
                    ii i = v;
                    while(i.fi != be){
                        ans.eb(i.se);
                        i = trace[i.fi];
                    }
                    reverse(all(ans));
                    for(int p : ans)
                        cout << p << " " ;
                    return;
                }
                q.push(v);
            }
        }
        q.pop();
    }
}

void init(){
    read(n), read(m), read(be), read(ed);
    int u, v;
    for(int i = 1; i <= m; i++){
        read(u), read(v);
        f[u].eb(make_pair(v, i));
    }
}
//-----TASK----------
#define task "BFS3"
//-------------------
int32_t main(){
    //---------------------------------
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    //---------------------------------
    init();
    solve();
}