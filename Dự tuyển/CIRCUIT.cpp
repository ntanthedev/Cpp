#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
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
        x = (x<<3) + (x<<1) + (c - 48);
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

const int N = 1e5+10;
const ll MOD = 1e9+7;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------Khai Bao
int n, m;
vii f[N], res;
vi ans;
bool flag = false;
unordered_map<int, int> M;
//----------------------------
void dfs(int x){
    M[x] = 1;
    for(ii v: f[x]){
        if(!ans.empty()) 
            return;
        res.eb(v);
        if(!M[v.fi])
            dfs(v.fi);
        else if(M[v.fi] == 1){
            for(int i = res.size(); i >= 0; i--){
                if(res[i].fi == res.back().fi && i < res.size()-1)
                    break;
                if(M[res[i].fi]==1)
                    ans.eb(res[i].se);
            }
            reverse(all(ans));
            return;
        }
    }
    M[x] = 2;
}
void solve(){
    for(int i = 1; i <= n; i++){
        if(M[i] == 0){
            dfs(i);
            if(!ans.empty()){
                cout<<"YES"<<'\n';
                for(int i: ans)
                    cout<<i<<" ";
                return;
            }
        }
    }
    cout<<"NO";
}

void init(){
    read(n), read(m);
    int u, v;
    for(int i = 1; i <= m; i++){
        read(u), read(v);
        f[u].eb(mp(v, i));
    }
}
//-----TASK----------
#define task "CIRCUIT"
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