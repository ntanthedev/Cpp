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

const int N = 1e6+10;
const ll MOD = 1e9+7;

bool is_prime[10000009];
//const int Max_Sang = 10000009;
void sang_eratosthene(ll Max_Sang){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i <= sqrt(Max_Sang); i++)
        if(is_prime[i])
            for(int j = i*i; j <= Max_Sang; j += i)
                is_prime[j] = false;
}
ll s[N], n, gmax, a[N];
priority_queue<ll, vll, greater<ll>> q;
void solve(){
    q.push(s[1]);
    sang_eratosthene(n+1);
    gmax = a[2];
    for(int i = 3; i <= n; i++) {
        //if(i == 2) continue;
        if(is_prime[i]) {
            gmax = max(gmax, a[i]);
            gmax = max(gmax, s[i] - q.top());
            q.push(s[i-1]);
            //cout << i << " " << q.top() << '\n';
        }
    }
    cout << gmax;
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
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