/* Author: Kritin Maddireddy
   Filename: C.Ferris_Wheel.cpp
   Date and Time of file creation: 26/7/23 11:35 PM
*/
 
#include <bits/stdc++.h>
 
 #pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U = null_type, class chash = hash <T>> using hset =
        gp_hash_table<T, U, chash>;
template<class T, class U = null_type, class cmp = less <T>> using oset =
        tree<T, U, cmp, rb_tree_tag, tree_order_statistics_node_update>;
 
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define pb push_back
#define ff first
#define ss second
#define int long long
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define IO(NAME) \
    cin.tie(0)->sync_with_stdio(0); \
    if(fopen(NAME ".in","r")) freopen(NAME ".in","r",stdin), \
    freopen(NAME ".out","w",stdout);
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <vii> vvii;
 
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

const int MOD = 1e9 + 7;
 
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// MODULO ARITHMETIC ALGORITHMS:
 
// Ways to calculate modulo multiplicative inverse, and power of a number under modulo m.
 
// Extended Euclid's GCD algorithm: (use ONLY if n and m are co-primes.)
int extendedEuclid(int n, int m) {
    int A1 = 1, A2 = 0, A3 = m;
    int B1 = 0, B2 = 1, B3 = n;
    while (B3 != 1) {
        if (B3 == 0) return -1; // No inverse exists.
        int Q = A3 / B3;
        int T1 = (A1 - (Q * B1)), T2 = (A2 - (Q * B2)), T3 = (A3 - (Q * B3));
        A1 = B1, A2 = B2, A3 = B3;
        B1 = T1, B2 = T2, B3 = T3;
    }
    return (B2 + m) % m;
}
 
// Power under modulo m
int powerModuloM(int n, int exponent, int m) {
    if (exponent == 0) return 1;
    int p = powerModuloM(n, exponent / 2, m) % m;
    p = (p * p) % m;
    return (exponent % 2 == 0) ? p : (n * p) % m;
}
 
// Fermat's little theorem: (if m is prime, then a^(m-1) = 1 (mod m), so, a^(m-2) = a^-1 (mod m). We also know that (a*b)%m = (a%m * b%m)%m.
int fermatLittleTheorem(int n, int m) {
    if (gcd(m, n) != 1) return -1; // Then, m is not prime and thus, modulo inverse doesn't exist.
    return powerModuloM(n, m - 2, m);
}
 
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// COMBINATORICS ALGORITHMS:
 
// nCr without modulo:
int nCr(int n, int r) {
    int ans = 1;
    if (n - r < r) r = n - r; // as nCr = nCn-r
    for (int i = 0; i <= r - 1; i++) ans = ((ans * (n - i)) / (i + 1));
    return ans;
}
 
// nCr under modulo:
int nCrUnderMOD(int n, int r) {
    int ans = 1;
    if (n - r < r) r = n - r; // as nCr = nCn-r
    for (int i = 0; i <= r - 1; i++)
        ans = ((ans % MOD * (n - i) % MOD) % MOD * fermatLittleTheorem(i + 1, MOD) % MOD) % MOD;
    return ans;
}
 
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// BINARY SEARCH ALGORITHMS:
 
// Binary search for first true: only if FALSE FALSE FALSE TRUE TRUE TRUE monotonic function is achieved:
int firstTrueBinarySearch(int lo, int hi,
                          function<bool(int)> f) { // Source: https://usaco.guide/silver/binary-search?lang=cpp
    // if none of the values in the range work, return hi + 1.
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
 
// Binary search for last true: only if TRUE TRUE TRUE FALSE FALSE FALSE monotonic function is achieved:
int lastTrueBinarySearch(int lo, int hi,
                         function<bool(int)> f) { // Source: https://usaco.guide/silver/binary-search?lang=cpp
    // if none of the values in the range work, return lo - 1
    lo--;
    while (lo < hi) {
        // find the middle of the current range (rounding up)
        int mid = lo + (hi - lo + 1) / 2;
        if (f(mid)) lo = mid; // if mid works, then all numbers smaller than mid also work.
        else hi = mid - 1; // if mid does not work, greater values would not work either.
    }
    return lo;
}
 
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// GRAPH ALGORITHMS (for Adjacency List):
 
int ROOT_TREE = -1; // CHANGE THIS FOR ROOTED TREE QUESTIONS!
 
// In the main function, you can call this on all connected components by iterating over vertices 1 to n. (or, 0 to n-1 depending on your indexing.)
// The visited array will take care of the current vertex being previously visited in some connected component.
void DFS(int currNode, vector <vector<int>> &adj, vector<bool> &visited) {
    if (visited[currNode]) return;
    visited[currNode] = true;
    bool isLeaf = false;
    if (adj[currNode].size() == 1 && currNode != ROOT_TREE) isLeaf = true; // Root node cannot be leaf.
    for (int neighbor: adj[currNode]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
            // Do something with current node and this neighbour here, if required...
        }
    }
    if (isLeaf) {
        // Leaf node has been detected, do something here...
    }
}
 
#define NOT_VISITED 0
#define ENQUEUED 1
#define PROCESSED 2
 
// In the main function, you can call this on all connected components by iterating over vertices 1 to n. (or, 0 to n-1 depending on your indexing.)
// The visited array will take care of the current vertex being previously visited in some connected component.
void BFS(int n, int source, vector <vector<int>> &adj, vector<int> &visited) {
    if (visited[source] == NOT_VISITED) {
        queue<int> q;
        visited[source] = ENQUEUED;
        q.push(source);
        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            visited[currNode] = PROCESSED; // fully processed.
            bool isLeaf = false;
            if (adj[currNode].size() == 1 && currNode != ROOT_TREE) isLeaf = true; // Root node cannot be leaf.
            for (int neighbor: adj[currNode]) {
                if (visited[neighbor] == NOT_VISITED) {
                    q.push(neighbor);
                    visited[neighbor] = ENQUEUED;
                    // Do something here with the neighbour that has just been pushed into the queue...
                }
            }
            if (isLeaf) {
                // Leaf node has been detected, do something here...
            }
        }
    }
}
 
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
// SIEVE OF ERATOSTHENES, AND EULER TOTIENT FUNCTION:
 
// Used to generate a list of all the primes from 1 to n -> basically, pre-compute them and use them later if required.
void SieveOfEratosthenes(int n) {
    bool *primeCheck = new bool[n + 1];
    memset(primeCheck, true, (n + 1) * sizeof(bool));
    // We start from p*p, because all those multiples of p smaller than p itself will already have been marked as not prime beforehand.
    // At this point, if primeCheck[p] is true, it means that it is a prime. If a multiple for p existed, we would've come across it before sqrt(p) only.
    for (int p = 2; p * p <= n; p++) if (primeCheck[p]) for (int i = p * p; i <= n; i += p) primeCheck[i] = false;
 
    for (int i = 2; i <= n; i++)
        if (primeCheck[i]) {
            // PROCESS THE primeCheck ARRAY -> ALL THE VALUES MARKED AS TRUE, ARE INDEED PRIMES.
            // DO SOMETHING WITH THEM HERE......
 
        }
    delete[] primeCheck; // Free the memory associated with it.
}
 
// Euler's Totient Function: phi(n) for an input n is the count of numbers {1, 2, ..., n-1} that are relatively prime (co-prime) to n, basically, it gives the
// number of numbers whose GCD with n is 1.
// Formula: phi(n) = n * product of (1 - 1/p) (where p is a prime factor of n).
int eulerTotientFunction(int n) {
    double numCoPrimes = n;
    for (int p = 2; p * p <= n; p++)
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            numCoPrimes *= (1.0 - (1.0 / (double) p));
        }
    if (n > 1) numCoPrimes -= numCoPrimes /
                              n; // Checks, if n has a prime factor greater than sqrt(n) (there can be at most 1).
    return (int) numCoPrimes;
}
 
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 
// Sort and 2 pointers: At every instance, try to pair up the lightest kid with the heaviest kid. If sum of weights is greater than that which can be
// accommodated in a gondola, then heaviest kid must get his own gondola. Else, you can pair with lightest kid, and get them both a gondola combined.
 
int32_t main() {
    fast;
    int t = 1;
    while(t--){
        int n, x;
        read(n), read(x);
        vector<int> v(n);
        for(int i = 0; i < n; i++) read(v[i]);
        std::sort(v.begin(), v.end());
        int leftPtr = 0, rightPtr = n-1, count = 0;
        while(leftPtr <= rightPtr){
            if(leftPtr == rightPtr) count++, leftPtr++;
            while(leftPtr < rightPtr && v[leftPtr] + v[rightPtr] > x) rightPtr--, count++;
            if(leftPtr < rightPtr && v[leftPtr] + v[rightPtr] <= x) rightPtr--, leftPtr++, count++;
        }
        cout << count << "\n";
    }
}