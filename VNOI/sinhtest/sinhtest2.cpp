#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;
#define el inp<<'\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const int btest = 1; 
const int etest = 50; // so luong test
const int test_for_sub1 = 60; //% so luong test theo tung sub
const int test_for_sub2 = 40;
const int test_for_sub3 = 00;
const int test_for_sub4 = 00;


// ll Rand(ll l, ll h)
// {
//     return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                 (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                 (ll)rand() * (RAND_MAX + 1) +
//                 rand()) % (h - l + 1);
// }

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l,r) (rd);
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

vector<pair<int, int> > graph(int ver, int edge) // tra ve cac canh cua mot do thi ngau nhien
{
    unordered_map<long long, bool> used;
    used[0] = true;

    vector<pair<int, int> > ans;
    for(int i = 1; i <= edge; i ++)
    {
        int a = 0, b = 0;
        while(a <= b or used[1LL * a * ver + b])
        {
            a = Rand(1, ver);
            b = Rand(1, ver);
        }
        used[1LL * a * ver + b] = true;
        if(Rand(0, 1)) swap(a, b);
        ans.push_back(make_pair(a, b));
    }

    int secret = 0;
    while(__gcd(secret, ver) != 1) secret = Rand(1, ver);
    for(int i = 0; i < edge; i ++)
    {
        ans[i].first = 1LL * ans[i].first * secret % ver;
        if(ans[i].first == 0) ans[i].first = ver;
        ans[i].second = 1LL * ans[i].second * secret % ver;
        if(ans[i].second == 0) ans[i].second = ver;
    }

    return ans;
}

vector<pair<int, int> > connected_graph(int ver, int edge) // tra ve cac canh cua mot do thi lien thong
{
    unordered_map<long long, bool> used;
    used[0] = true;

    vector<pair<int, int> > ans;
    for(int i = 2; i <= ver; i ++)
    {
        ans.push_back(make_pair(i, Rand(1, i - 1)));
        used[1LL * ans.back().first * ver + ans.back().second] = true;
    }
    for(int i = ver; i <= edge; i ++)
    {
        int a = 0, b = 0;
        while(a <= b or used[1LL * a * ver + b])
        {
            a = Rand(1, ver);
            b = Rand(1, ver);
        }
        used[1LL * a * ver + b] = true;
        if(Rand(0, 1)) swap(a, b);
        ans.push_back(make_pair(a, b));
    }

    for(int i = 0; i < edge; i ++) swap(ans[i], ans[Rand(0, i)]);

    int secret = 0;
    while(__gcd(secret, ver) != 1) secret = Rand(1, ver);
    for(int i = 0; i < edge; i ++)
    {
        ans[i].first = 1LL * ans[i].first * secret % ver;
        if(ans[i].first == 0) ans[i].first = ver;
        ans[i].second = 1LL * ans[i].second * secret % ver;
        if(ans[i].second == 0) ans[i].second = ver;
    }

    return ans;
}


#define maxn 2003
//#define A 1000000000
const ll A = 1e18;
const ll H = 1e12;
const ll N = 1e6 + 10;
const ll Q = 1e5;
const ll X = 2e9;
const ll K = 1e9;
const ll W = 1e6;
const ll T = 10;

int cal(int x, int n) {
    return double(n / 100.0) * x;
}

int n, k;
bool p[N + 10];
vector<int> a, b(N + 10, 0);
vector<pair<int, int>> m;

void sang() {
    memset(p, true, sizeof(p));

    p[0] = p[1] = false;

    for(int i = 2; i <= sqrt(N); i++) 
        if(p[i]) 
            for(int j = i * i; j <= N; j += i) 
                p[j] = 0;
}

void solve() {
    sang();

    for(int i = 1; i <= N; i++) 
        if(p[i]) 
            a.pb(i);

    for(int i = 1; i < a.size(); i++) {
        int t = a[i] + a[i - 1];
        if(t <= N && p[t + 1]) {
            b[t + 1] = 1;
            m.push_back({t + 1, (m.size() ? m.back().second + 1 : 1)});
        } 
    }
    
    for(int i = 1; i <= N; i++) 
        b[i] += b[i - 1];
}

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    n = Rand(1, 1e3);

    auto t = *--upper_bound(all(m), make_pair(n, INT_MAX));

    k = t.second + Rand(-5, 5);

    inp << n << " " << k << '\n';
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    n = Rand(1e5, 1e6);

    auto t = *--upper_bound(all(m), make_pair(n, INT_MAX));

    k = t.second + Rand(-5, 5);

    inp << n << " " << k << '\n';
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

}

void sub4(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());


}

int main() {
    // ios_base::sync_with_stdio(false);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));

    int total_test = etest;
    int s1 = cal(test_for_sub1, total_test);
    int s2 = s1 + cal(test_for_sub2, total_test);
    int s3 = s2 + cal(test_for_sub3, total_test);

    solve();

    for (int i = btest; i <= etest; i++)
    {
        if(i <= s1) {
            
            sub1(i);
        }
        else if(i <= s2) {
            
            sub2(i);
        }
        else if(i <= s3) {

            sub3(i);
        } 
        else {
            sub4(i);
        }
        cerr << "test " << i << '\n';
    }

    return 0;
}
