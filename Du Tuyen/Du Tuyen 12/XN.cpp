//problem "XN"
//created in 08:52:11 - Mon 22/07/2024

#include<bits/stdc++.h>

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

bool check(vector<vector<int>> a, vector<vector<int>> group, int x, int y) {
    int m = a[y].size();
    int k = a[x][0] <= a[y][0] ? 1 : 0;

    for(auto i : group[x]) {
        for(int j = 0; j < m; j++) 
            if((a[i][j] > a[y][j] && k) || (a[i][j] < a[y][j] && !k))
                return false;
    }

    return true;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "XN"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> group(n, vector<int>());
    vector<int> g(n, 0);
    int cnt = 0;

    for(auto &vt : a) 
        for(auto &i : vt)
            cin >> i;

    for(int i = 0; i < n; ++i) {
        if(g[i])
            continue;
        else {
            g[i] = ++cnt;
            group[i].push_back(i);
        }
        for(int j = i + 1; j < n; ++j) {
            // int check = 1;
            // for(int it = 1; it < m; it++) {
            //     if((a[i][it] <= a[j][it] && a[i][0] <= a[j][0]) || (a[i][it] >= a[j][it] && a[i][0] >= a[j][0]))
            //         check = 1;
            //     else {
            //         check = 0;
            //         break;
            //     }
            // }
            if(check(a, group, i, j)) {
                g[j] = g[i];
                group[i].push_back(j);
            }
        }
    }

    if(cnt > k) 
        return cout << -1, 0;
    
    if(cnt < k) {
        for(int i = 0; i < n; ++i) {
            while(group[i].size() > 1 && cnt < k) {
                int j = group[i].back();
                group[j].push_back(j);
                group[i].pop_back();
                ++cnt;
            }
            if(cnt == k)
                break;
        }
    }

    dbg(group)
    
    for(auto i : group) 
        if(!i.empty()) {
            for(auto j : i)
                cout << j + 1 << " ";
            cout << '\n';
        }
}