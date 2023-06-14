#include<bits/stdc++.h>
//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define task ""
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
const int Max_Sang = 70;
vi primes;
void sang_eratosthenes(){
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i * i <= Max_Sang; i++)
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i*i; j <= Max_Sang; j += i)
                is_prime[j] = false;
        }
}

int simplify(int x) {
    int ans = 1;
    for(int i = 2; i * i <= x; i++) {
        int c = 0;
        while(x % i == 0) {
            c++;
            x /= i;
        }
        if(c & 1) ans *= p;
    }
    if(x != 1) ans *= x;
    return ans;
}

ll modpow(ll b, ll e) {
    ll ans = 1;
    while(e) {
        if(e & 1) ans = ans * b % MOD;
        b = b * b % MOD;
        e >>= 1;
    }
    return ans;
}

void solve(){
    sang_eratosthenes();
    int n;
    cin >> n;
    vi a(n);
    vi cnt(71, 0);
    // primes.size() == 19
    for(int i = 0; i < n; i++) cin >> a[i], a[i] = simplify(a[i]), cnt[a[i]]++;

    vll dp(1 << 20), last(1 << 20);
    // mask, 1 bit the hien la so mu cua primes[i] co le hay khong
    // 2
    // 10000 = 2 ^ 1
    dp[0] = 1;
    last[0] = 1;
    // xet den thang i = 0
    // dp[0] bieu dien so cach chon cac so sao cho tich cua chung rut gon va xu ly mask co dang 0
    // 1 * 3 = 3 ^ 1
    // 3 => 010000
    // {2, 3, 5, 7, ...}
    for(int i = 1; i <= 70; i++) {
        if(cnt[i] == 0) continue;

        int state = 0;
        for(int j = 0; j < primes.size(); j++)
            if(i % primes[j] == 0) {
                state ^= 1 << j;
            }
        
        // 2 ^ (cnt[i] - 1)
        // 2 ^ (cnt[i] - 1)
        ll ways = modpow(2, cnt[i] - 1);
        for(int mask = 0; mask < (1 << 19); mask++) {
            dp[mask ^ state] += last[mask] * ways % MOD;
            dp[mask ^ state] %= MOD;
            dp[mask] += last[mask] * ways % MOD;
            dp[mask] %= MOD;
        }

        swap(dp, last);
        vll(1 << 20, 0).swap(dp);
    }

    cout << (dp[0] - 1 + MOD) % MOD << endl;
}

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
        solve();
    }
}