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
ll m, n, bg, ed, l[N], trace[N];
umib M;
vll g[N], ans;
queue<ll> q;
//----------------------------
void solve(){
    for(int i = 1; i <= n; i++)
        sort(all(g[i]));
    l[bg] = 0;
    M[bg] = 1;
    while(!q.empty()){
        for(int v : g[q.front()]){
            if(!M[v]){
                M[v] = 1;
                trace[v] = q.front();
                l[v] = l[q.front()] + 1;
                if(v == ed){
                    ll i = v;
                    while(i != bg){
                        ans.eb(i);
                        i = trace[i];
                    }
                    ans.eb(bg);
                    reverse(all(ans));
                    for(int i : ans)
                        cout<<i<<" ";
                    return;
                }
                q.push(v);
            }
        }
        q.pop();
    }    
}

void init(){
    read(n), read(m), read(bg), read(ed);
    ll u, v;
    for(int i = 1; i <= m; i++){
        read(u), read(v);
        g[u].eb(v);
    }
    q.push(bg);
}
//-----TASK----------
#define task "BFS2"
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