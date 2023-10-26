#include<bits/stdc++.h>
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
ll n, x, y;
//----------------------------4
struct pt{
    ll fi, se, vt;
};
pt a[N];
vector<pt> ans;
bool cmp(pt c, pt d){
    return c.fi < d.fi || (c.fi == d.fi && c.se < d.se);
}
bool sortvitri(pt c, pt d){
    return c.vt < d.vt;
}
void solve(){
    sort(a+1, a+1+n, cmp);
    ll d;
    //cout<<"----------------\n";
    // for(int i = 1;  i <= n; i++)
    //     cout << a[i].fi << " " << a[i].se << " " << a[i].vt << '\n';
    // cout<<"----------------\n";
    ll t = -1;
   // a[n+1].se = a[n+1].fi = LLONG_MAX;
    for(int i = 1; i <= n; i++){
        if(x >= a[i].fi && x <= a[i].se){
            t = i;
        }
    }
  //  cout<<"t: "<<t<<'\n';
    if(t == -1){
        cout<<t;
        return;
    }
    ans.eb(a[t]);
    // if(ans.back().se >= y){
    //     cout<<ans.size()<<'\n';
    //     for(auto v:ans)
    //         cout<<v.vt<<'\n';
    //     return;
    // }
    d = x;
    for(int i = t+1; i <= n; i++){
        if(a[i].se <= ans.back().se || a[i].fi == a[i].se)
            continue;
        if(a[i].fi <= ans.back().se){
            if(a[i].fi <= d) 
                ans.pop_back();
            d = ans.back().se;
            ans.eb(a[i]);
        } 
        if(ans.back().se >= y)
            break;
    }
    if(ans.back().se < y){
        cout<<-1;
        return;
    }
    sort(all(ans), sortvitri);
    cout<<ans.size()<<'\n';
    for(pt v:ans)
        cout<<v.vt<<'\n';
}

void init(){
    cin >> n >> x >> y;
    for(int i = 1;  i <= n; i++){
        cin >> a[i].fi >> a[i].se;
        a[i].vt = i;
    }
}
//-----TASK----------
#define task "COVER"
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
    