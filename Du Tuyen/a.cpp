// problem "a"
// created in 09:59:05 - Sat 20/07/2024

#include <bits/stdc++.h>

// #define int int64_t

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

vector<int> prefix_function(string s) {
    int n = (int) s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    if(n > m)
        swap(m, n), swap(a, b);
    dbg(n) 
    dbg(m)
    vector<int> u;
    for(int i = 1; i <= sqrt(n); ++i) {
        if(n % i == 0 && m % i == 0) {
            u.push_back(i);
            if(i * i != n && m % (n / i) == 0)
                u.push_back(n / i);
        }
    }
    dbg(u)
    string c = a + '#' + b;
    vector<int> pi = prefix_function(c), ans(n + m + 1, 1);
    vector<int> p = prefix_function(a), s(n + 1, 1);
    dbg(pi)
    dbg(p)
    cerr << "c: " << c << '\n';
    // exit(0);
    int res = 0;

    for(int i = n + m; i > 0; i--)
        if(pi[i])
            ans[pi[i] - 1] += ans[i];

    for(int i = n - 1; i > 0; i--)
        if(p[i])
            s[p[i] - 1] += s[i];
    dbg(ans)
    dbg(s)
    for(auto v: u) {
        for(int i = n + v; i <= m + n; i += v) {
            if(pi[i] >= m / v && p[n - v - 1] >= n / v)
                res++;
        }
    }

    cout << res;
}

/*
abcd
abcdabcd
abcd#abcdabcd
0123456789012
*/