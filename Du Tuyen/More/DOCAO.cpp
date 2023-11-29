#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6+10;
const ll MOD = 1e9+7;

ll n, h, cnt = 0;
vi p;

bool is_prime[1000009];
const int Max_Sang = 1000009;
void sang_eratosthene(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i <= sqrt(Max_Sang); i++)
        if(is_prime[i])
            for(int j = i*i; j <= Max_Sang; j += i)
                is_prime[j] = false;
}

void solve() {
    
}

void init() {
    sang_eratosthene();
    cin >> n >> h;
    for(int i = 1; i <= n; i++) 
        if(is_prime[i]) {
            ll t = i, s = 0;
            while(t > 0) {
                s += t%10;
                t /= 10;
            }
            if(s == h) {
                cout << i << '\n';
                cnt++;
            }
        }
    cout << cnt;
}

#define task "DOCAO"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        init();
        solve();
    }
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}