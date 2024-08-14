//problem "FACTORIAL"
//created in 07:43:55 - Wed 14/08/2024

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3e6 + 6;

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

ll n, Fs = 0;
string s, z;
ll F[10];
vector<vector<pair<int, int>>> c(10, vector<pair<int, int>>());

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s >> z;

    F[1] = 1;
    for(int i = 2; i <= 9; i++) {
        F[i] = F[i - 1] * i;
    }

    int res = 1;
    for(int i = 0; i < s.size(); i++) {
        res *= F[s[i] - '0'];
    }

    int ress = 1;
    for(int i = 0; i < z.size(); i++) {
        ress *= F[z[i] - '0'];
    }

    cout << res << '\n' << ress;
}

/*
9 = 8! * 9 = 7! * 8 * 9 = 7! * 2 * 2 * 2 * 3 * 3 = 3! * 3! * 2;
8 = 7! * 2 * 2 * 2;
*/