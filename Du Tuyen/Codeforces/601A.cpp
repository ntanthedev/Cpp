//Written by: ntannn_
//problem "601A"
//created in 11:07:08 - Fri 14/06/2024

#include<bits/stdc++.h>

// #define int int64_t
#define all(x) x.begin(), x.end()

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

int n, m;

int bfs(vector<vector<int>> f) {
    queue<int> q;
    vector<int> d(n + 1, -1);

    q.push(1);
    d[1] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(auto i : f[u]) {
            if(d[i] == -1) { 
                q.push(i);
                d[i] = d[u] + 1;
            }
        } 
    }

    return d[n];
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>()), b(n + 1, vector<int>());
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++)
            if(j != i)
                b[i].push_back(j);
    for(int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        b[x].erase(lower_bound(all(b[x]), y));
        b[y].erase(lower_bound(all(b[y]), x));
    }

    int train = (find(all(a[1]), n) == a[1].end()); // 0 is train
    // cout << "train: " << train << '\n';
    // cout << "a: \n";
    // for(int i = 1; i < a.size(); cout << '\n', i++)
    //     for(auto j : a[i])
    //         cout << j << " ";
    // cout << "b: \n";
    // for(int i = 1; i < b.size(); cout << '\n', i++)
    //     for(auto j : b[i])
    //         cout << j << " ";

    cout << bfs((train ? a : b));
}
// A: 1 -> x -> y -> n...
// => 1 - > n???
//oh shit :Đ