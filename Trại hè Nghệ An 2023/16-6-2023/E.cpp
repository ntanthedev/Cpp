#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")

using namespace std;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()


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
    dbg(v[10])
    for(int i = 1; i <= N; i++) {
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
        if(fre)
            cout << i << " " << fre << '\n';
        if(!q.empty())
            cout << i << " " << q.front() << '\n';
        while(fre > 0) {
            ans.eb(i);
            //q.pop();
            if(i == 10)
                cout<<"fre\n";
            fre--;
        }
        if(!q.empty()) {
            //cout << q.front() << '\n';
            for(auto j : v[i]) {
                if(!M[j]){
                    //cout << j << '\n';
                    q.pop();
                    ans.eb(i);
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