#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define fi first
#define se second
#define mp make_pair
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

const int MaxN = 35*35;
const ll MOD = 111539786;

bool is_prime(int x)
{
    for(int i = 2 ; i * i <= x ; i++)
        if(x%i == 0)
            return 0;
    return 1;
}
//----------------------------//
ll m, N, n;
int a[MaxN][MaxN], b[MaxN][MaxN];
//----------------------------
inline int get_id(int i, int j){
    return (i-1)*n + j;
}
void solve(){
    ll ans = 1;
    for(int i = 1; i <= N; i++){
        bool flag = 0;
        for(int j = 1; j <= N; j++){
            if(b[i][j]){
                for(int k = i+1; k <= N; k++){
                    if(b[k][j]){
                        if(b[k][j] == b[i][j])
                            for(int z = 0; z <= N; z++)
                                b[k][z] = (b[k][z] + 2*b[i][z])%3;
                        else
                            for(int z = 0; z <= N; z++)
                                b[k][z] = (b[k][z] + b[i][z])%3;
                    }                   
                }
                flag = true;
                    break;
            }            
        }
        if(!flag) {
            if(b[i][0]) 
                ans = 0;
            else 
                ans = (ans*3)%MOD;
        }
    }
    cout << ans%MOD;
}

void init(){
    cin >> m >> n;
    N = m*n;
    memset(b, 0, sizeof(b));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            if(a[i][j] != -1){
                if(i < m) b[get_id(i, j)][get_id(i+1, j)] = 1;
                if(j < n) b[get_id(i, j)][get_id(i, j+1)] = 1;
                if(i > 1) b[get_id(i, j)][get_id(i-1, j)] = 1;
                if(j > 1) b[get_id(i, j)][get_id(i, j-1)] = 1;
                b[get_id(i, j)][0] = a[i][j];
            }
        }
    
}
//-----TASK----------
#define task "TABLE3"
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
