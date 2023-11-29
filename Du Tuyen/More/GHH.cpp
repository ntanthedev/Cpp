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

ll n, x;

int smallest_divisor[N + 1];
bool is_prime[N + 1];

void eratosthenes_sieve(int N)
{
    // Mảng lưu ước nguyên tố nhỏ nhất của các số trong đoạn [1, N].
    fill(smallest_divisor + 1, smallest_divisor + N + 1, 0); 
    fill(is_prime, is_prime + N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; ++i)
        if (is_prime[i]) // Nếu i là số nguyên tố
            for (int j = i * i; j <= N; j += i)
            {
                is_prime[j] = false;
                    
                // Ước nguyên tố nhỏ nhất của j là i.
                if (smallest_divisor[j] == 0)
                    smallest_divisor[j] = i; 
            }

    // Xét riêng các trường hợp i là số nguyên tố,
    // ước nguyên tố nhỏ nhất là chính nó.
    for (int i = 2; i <= N; ++i)
        if (is_prime[i])
            smallest_divisor[i] = i;
}

vector < int > extract(int n)
{
    // Sàng số nguyên tố tới một giá trị N nào đó. 
    eratosthenes_sieve(N); 

    vector < int > prime_factor;

    while (n > 1)
    {
        int p = smallest_divisor[n];
        prime_factor.push_back(p);
        n /= p;
    }

    return prime_factor;
}


long long exponentiation(long long A, long long B)
{
    if (B == 0)
        return 1LL;

    long long half = exponentiation(A, B / 2LL);

    if (B & 1)
        return half * half * A;
    else 
        return half * half;
}

long long get_sum_divisors(int n)
{
    long long x = 1, y = 1;
    
    while (n > 1)
    {
        int d = smallest_divisor[n], power = 0;
        while (n % d == 0)
        {
            ++power;
            n /= d;
        }

        x *= (exponentiation(d, power + 1) - 1);
        y *= (d - 1);
    }

    return x / y;
}


void solve() {
    if(get_sum_divisors(x) >= 2*x)
        cout << 1 << '\n';
    else 
        cout << 0 << '\n';
}

void init() {
    eratosthenes_sieve(N); 
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        solve();
    }
}

#define task "GHH"
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
        // solve();
    }
    //cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}