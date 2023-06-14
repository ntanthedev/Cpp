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
ll n, a[N], k, s = -1;
vi ans;
umll M;
//----------------------------
void solve(){
    for(int i = 1; i < n; i++){
        for(int j = i+1; j <= n; j++){
            M[a[i] + a[j]] = 1;
        }
    }
    bool flag = false;
    for(int i = 1; i < n; i++){
        if(!flag)
            for(int j = i+1; j <= n; j++){
                if(M[k - a[i] - a[j]]){
                    s = k - a[i] - a[j];
                    a[i] = -1;
                    a[j] = -1;
                    ans.eb(i);
                    ans.eb(j);
                    flag = 1;
                    break;
                }
            }
    }
    flag = 0;
    if(s != -1){
        for(int i = 1; i < n; i++){
            if(!flag)
                for(int j = i+1; j <= n; j++){
                    if(a[i] + a[j] == s){
                        ans.eb(i);
                        ans.eb(j);
                        flag = 1;
                        break;
                    }
                }
        }
        sort(all(ans));
        for(int i : ans)
            cout<<i<<" ";
    }
    else
        cout << "IMPOSSIBLE";
}

void init(){
    read(n), read(k);
    for(int i = 1; i <= n; i++)
        read(a[i]);
}
//-----TASK----------
#define task "sum4val"
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