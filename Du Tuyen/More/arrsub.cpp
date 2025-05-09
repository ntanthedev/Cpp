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
        x = x * 10 + (c - 48);
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
//----------------------------Khai Bao
ll n, a[N], k;
deque<ll> dq;
//----------------------------
void solve(){
    for(int i = 1; i <= k-1; i++){
        while(!dq.empty() && dq.back() <= a[i])
            dq.pop_back();
        dq.pb(a[i]);        
    }
    for(int i = k; i <= n; i++){
        while(!dq.empty() && dq.back() <= a[i])
            dq.pop_back();
        dq.push_back(a[i]);
        cout<<dq.front()<<" ";
    }
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> k;
}
//-----TASK----------
#define task "arrsub"
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