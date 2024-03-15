#include <bits/stdc++.h>
#define N 3000000
#define ll long long
#define MOD 123456789
using namespace std;
int p[N + 3];
int n;
void phantich(int x) {
    for(int i = 2; i * i <= x; i++) {
        while(x % i == 0) {
            p[i]++;
            x /= i;
        }
    }
    if(x > 1)
        p[x]++;
}
int main() {
    freopen("divisor.inp", "r", stdin);
    freopen("divisor.out", "w", stdout);
    cin >> n;
    for(int x, i = 1; i <= n; i++) {
        cin >> x;
        if(x > 1)
            phantich(x);
    }
    ll ans = 1;
    for(int i = 2; i <= N; i++)
        ans = (ans * (p[i] + 1)) * 1LL % MOD;
    cout << ans;
    return 0;
}

// #include<bits/stdc++.h>
// #define ll long long
// #define xau "DIVISOR"
// const int N = 1e6+9;
// using namespace std;
// ll n, k, a[N], pod = 0;

// void sub1(){
//     for(int i = 1; i <= sqrt(n); i++){
//         if(n%i == 0){
//             a[++pod] = i;
//             if(n/i != i)
//                 a[++pod] = n/i;
//         }
//     }
//     sort(a+1, a+1+pod);
//     if(pod < k)
//         cout<<-1;
//     else
//         cout<<a[k];
// }
// //---------------------------------------------------------
// long long indian_multiplication(ll a, ll b, ll mod)
// {
//     if (b == 0)
//         return 0LL;

//     long long half = indian_multiplication(a, b / 2LL, mod) % mod;

//     if (b & 1)
//         return (half + half + a) % mod;
//     else
//         return (half + half) % mod;
// }

// ll modular_exponentiation(ll a, ll b, ll mod)
// {
//     if (b == 0)
//         return 1LL;

//     ll half = modular_exponentiation(a, b / 2LL, mod) % mod;
//     ll product = indian_multiplication(half, half, mod);

//     if (b & 1)
//         return indian_multiplication(product, a, mod);
//     else
//         return product;
// }

// bool fermat_checking(ll n, int k = 50)
// {
//     if (n < 4)
//         return n == 2 || n == 3;

//     if (n != 2 && n % 2 == 0)
//         return false;

//     for (int i = 1; i <= k; ++i)
//     {
//         long long a = 2 + rand() % (n - 3);
//         if (modular_exponentiation(a, n - 1, n) != 1)
//             return false;
//     }

//     return true;
// }
// vector < ll > eratosthenes_sieve(ll max_value)
// {
//     vector < bool > is_prime(max_value + 1, true);
//     is_prime[0] = is_prime[1] = false;

//     for (int i = 2; i * i <= max_value; ++i)
//         if (is_prime[i])
//             for (int j = i * i; j <= max_value; j += i)
//                 is_prime[j] = false;

//     vector < ll > primes;
//     for (int i = 2; i <= max_value; ++i)
//         if (is_prime[i])
//             primes.push_back(i);

//     return primes;
// }

// ll solution(ll n)
// {
//     vector < ll > primes = eratosthenes_sieve(1000000);
//     long long res = 1;
//     for (ll p: primes)
//     {
//         if (p * p * p > n)
//             break;

//         ll cnt = 0;
//         while (n % p == 0)
//         {
//             n /= p;
//             ++cnt;
//         }

//         res *= (cnt + 1);
//     }
//     if (fermat_checking(n))
//         res *= 2LL;
//     else
//     {
//         int squaroot = sqrt(n);
//         if (squaroot * squaroot == n && fermat_checking(squaroot))
//             res *= 3;
//         else if (n != 1)
//             res *= 4;
//     }

//     return res;
// }
// void sub2(){
//     ll t = solution(n);
//     if(t < k){
//         cout<<-1;
//         return;
//     }
//     if(t == k){
//         cout<<n;
//         return;
//     }
//     ll l = 1, r = t;
//     for(int i = 2; i <= sqrt(n); i++){
//         if(n%i == 0){
//             l++;
//             r--;
//             if(l == k){
//                 cout<<i;
//                 return;
//             }
//             if(r == k){
//                 cout<<n/i;
//                 return;
//             }
//         }
//     }
// }
// //-----------------------------------------------------
// void solve(){
//     if(n <= 1e14)
//         sub1();
//     else
//         sub1();
// }

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);
//     if(fopen(xau".inp","r")){
//         freopen(xau".inp","r",stdin);
//         freopen(xau".out","w",stdout);
//     }
//     else{
//         freopen("a.inp","r",stdin);
//         freopen("a.out","w",stdout);
//     }
//     cin >> n >> k;
//     ll t = solution(n);
//     if(t < k){
//         cout<<-1;
//         return 0;
//     }
//     if(t == k){
//         cout<<n;
//         return 0;
//     }
//     solve();
// }
