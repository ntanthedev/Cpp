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

int n, maxx = 0, maxy = 0, sx[N];
ii a[N];
vi c;
map<int, int> M;
void nen(){
    int pos = 1;
    sort(all(c));
    for(auto i : c) {
        if(!M[i])
            M[i] = pos++;
        else 
            M[i] = pos;
    }
    for(int i = 1 ; i <= n; i++) {
        a[i].fi = M[a[i].fi];
        a[i].se = M[a[i].se]; 
        sx[a[i].fi]++;
    }
}                                                                                                
void solve(){
    nen();
    for(int i = 1; i <= n; i++) {

    }
}

void init(){
    cin >> n;
    c.reserve(N);
    for(int i = 1 ; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        c.eb(N);
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