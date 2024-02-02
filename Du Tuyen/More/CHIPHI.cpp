// template for some simple code by ntannn_
// created in 07:20:56 - Thu 01/02/2024
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
// #define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;

const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;

template<typename T>
inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}

vector<int> primes;

int indian_multiplication(int a, int b, int mod) {
    if(b == 0)
        return 0;

    int half = indian_multiplication(a, b / 2LL, mod) % mod;

    if(b & 1)
        return (half + half + a) % mod;
    else
        return (half + half) % mod;
}

int modular_exponentiation(int a, int b, int mod) {
    if(b == 0)
        return 1LL;

    int half = modular_exponentiation(a, b / 2LL, mod) % mod;
    int product = indian_multiplication(half, half, mod);

    if(b & 1)
        return indian_multiplication(product, a, mod);
    else
        return product;
}

vector<int> eratosthenes_sieve(int max_value) {
    vector<bool> is_prime(max_value + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i * i <= max_value; ++i)
        if(is_prime[i])
            for(int j = i * i; j <= max_value; j += i)
                is_prime[j] = false;

    vector<int> primes;
    for(int i = 2; i <= max_value; ++i)
        if(is_prime[i])
            primes.push_back(i);

    return primes;
}

bool check_prime_by_miller_rabin(int n, int k) {
    if(n < 2)
        return false;

    if(n != 2 && n % 2 == 0)
        return false;

    int d = n - 1;
    while(d % 2 == 0)
        d /= 2;

    vector<int> mlc = {2, 3, 31, 73};
    for(int i = 1; i <= k; ++i) {
        int a = mlc[i - 1];
        int temp = d;

        int mod_val = modular_exponentiation(a, temp, n);

        while(temp != n - 1 && mod_val != 1 && mod_val != n - 1) {
            mod_val = indian_multiplication(mod_val, mod_val, n);
            temp *= 2;
        }
        if(mod_val != n - 1 && temp % 2 == 0)
            return false;
    }

    return true;
}

bool sqrt_is_integer(int n) {
    int squaroot = sqrt(n);

    return (squaroot * squaroot == n);
}

int solution(int n, int k) {
    long long res = 1;
    for(int p: primes) {
        if(p * p * p > n)
            break;

        int cnt = 0;
        while(n % p == 0) {
            n /= p;
            ++cnt;
        }

        res *= (cnt + 1);
    }

    if(check_prime_by_miller_rabin(n, k))
        res *= 2LL;
    else if(sqrt_is_integer(n) && check_prime_by_miller_rabin((int) sqrt(n), k))
        res *= 3LL;
    else if(n != 1)
        res *= 4LL;

    return res;
}

void solve() {
    int m, n;
    read(m), read(n);
    vvi a(m + 1, vi(n + 1)), dp(m + 1, vi(n + 1, 0)), u(m + 1, vi(n + 1));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            u[i][j] = solution(a[i][j], 4) - 1;
        }

    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + u[i][j];
        }
    cout << dp[m][n] << '\n';
}

#define task "CHIPHI"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    primes = eratosthenes_sieve(1000000);
    int test_case = 1;
    read(test_case);
    while(test_case--) {
        // init();
        solve();
    }
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}