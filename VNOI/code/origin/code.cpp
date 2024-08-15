<<<<<<< HEAD
//Written by: ntannn_
//created in 23:01:03 - Wed 14/08/2024
#include <bits/stdc++.h>
// #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
// #pragma GCC target("sse4,avx2,fma")
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

const int N = 1e7 + 10;
const ll MOD = 1e9 + 7;

template<typename T> inline void read(T& x) {
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

ll n;

void solve() {
    read(n);
    ll x = 0, tmp;
    for(int i = 1; i <= n; i++) {
        read(tmp);
        x ^= tmp;
    }
    cout << x;
}

#define task "code"
signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int test_case = 1;
    //cin >> test_case;
    while(test_case--) {
        solve();
    }
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
=======
#include <bits/stdc++.h>
using namespace std;

// Return sum of product of each element
// with each element after it
long long findSumofProduct(int arr[], int n)
{
    long long suffix_sum = arr[n - 1];

    // Finding product of array elements and
    // suffix sum.
    long long res = 0;
    for (int i = n - 2; i >= 0; i--) {

        res += (suffix_sum * arr[i]);

        // finding suffix sum
        suffix_sum += arr[i];
    }

    return res;
}

const int maxN=1000005;
// Driven Program
int n, arr[maxN];
int main()
{
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    cout << findSumofProduct(arr, n) << endl;
    return 0;
}
>>>>>>> a3d6f1bc661e497ea3816158ccd23fb77f4f1960
