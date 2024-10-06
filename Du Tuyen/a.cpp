#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l,r) (rd);
} 

// Hàm sinh cây ngẫu nhiên bằng cách sử dụng Prüfer sequence
vector<pair<int, int>> generateRandomTree(int n) {
    vector<pair<int, int>> edges;
    if(n == 1) return edges;

    // Sinh chuỗi Prüfer ngẫu nhiên
    vector<int> prufer(n-2);
    for(auto &x : prufer) x = rand() % n + 1;

    // Đếm số lần xuất hiện của mỗi đỉnh
    vector<int> degree(n+1, 1);
    for(auto x : prufer) degree[x]++;

    // Sử dụng min-heap để tìm đỉnh có số degree = 1 nhỏ nhất
    priority_queue<int, vector<int>, std::greater<int>> pq;
    for(int i=1; i<=n; ++i) if(degree[i] == 1) pq.push(i);

    // Xây dựng các cạnh từ chuỗi Prüfer
    for(auto x : prufer){
        int u = pq.top(); pq.pop();
        edges.emplace_back(u, x);
        degree[x]--;
        if(degree[x] == 1) pq.push(x);
    }

    // Hai đỉnh cuối cùng
    int u = pq.top(); pq.pop();
    int v = pq.top(); pq.pop();
    edges.emplace_back(u, v);

    return edges;
}

vector<pair<int, int>> generatePathTree(int n){
    vector<pair<int, int>> edges;
    for(int i=1; i<n; ++i){
        edges.emplace_back(i, i+1);
    }
    return edges;
}

vector<pair<int, int>> generateStarTree(int n){
    vector<pair<int, int>> edges;
    for(int i=2; i<=n; ++i){
        edges.emplace_back(1, i);
    }
    return edges;
}

vector<pair<int, int> > tree(int ver) // sinh mot cay va tra ve cac canh
{
    vector<pair<int, int> > ans;
    for(int i = 2; i <= ver; i ++)
        ans.push_back(make_pair(i, Rand(1, i - 1)));

    for(int i = 1; i < ver - 1; i ++) swap(ans[i], ans[Rand(0, i)]);

    int secret = 0;
    while(__gcd(secret, ver) != 1) secret = Rand(1, ver);
    for(int i = 0; i < ver - 1; i ++)
    {
        ans[i].first = 1LL * ans[i].first * secret % ver;
        if(ans[i].first == 0) ans[i].first = ver;
        ans[i].second = 1LL * ans[i].second * secret % ver;
        if(ans[i].second == 0) ans[i].second = ver;
    }

    return ans;
}



int main(){
    srand(time(0)); // Khởi tạo seed ngẫu nhiên

    int n;
    // Ví dụ: sinh cây với n = 100
    n = 10;

    // Sinh cây ngẫu nhiên
    vector<pair<int, int>> edges = tree(n);

    // Gán trọng số ngẫu nhiên cho các cạnh
    vector<tuple<int, int, int>> weightedEdges;
    for(auto &[u, v] : edges){
        int w = rand() % 10000 + 1; // Trọng số từ 1 đến 10000
        weightedEdges.emplace_back(u, v, w);
    }

    // In ra định dạng testcase
    cout << n << "\n";
    for(auto &[u, v, w] : weightedEdges){
        cout << u << " " << v  << "\n";
    }

    return 0;
}
