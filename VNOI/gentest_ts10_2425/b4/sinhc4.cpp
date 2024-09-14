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
const int etest = 100;
const int s1 = double(etest) / 100.0 * 40.0;
const int s2 = s1 + double(etest) / 100.0 * 30.0;


ll Rand(ll l, ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
#define maxn 2003
//#define A 1000000000
const ll A = 1e18;
const ll H = 1e12;
const ll N = 1e3;
const ll Q = 1e5;
const ll X = 2e9;
const ll K = 1e9;
const ll W = 1e6;
const ll T = 10;
map<ll, ll> M;
vector<long long> vt;
mt19937 rd(time(nullptr));

int cal(int x, int n) {
    return double(n / 100.0) * x;
}

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, b, q, k;
    n = Rand(1, N);
    if(x >= cal(50, s1)) // giới hạn hơn 50% test có n đạt giá trị giới hạn
        n = N;           // của sub tasks
    if(x <= s1 / 3)
        k = Rand(1, 100); // 1/3 test đầu của sub1 có k nhỏ (k <= 100)
    else if(x <= 2 * s1 / 3.0)
        k = Rand(100, n); // 2/3 test sau có k lớn hơn 
    else 
        k = Rand(1, N); // 1/3 test cuối, k đạt giá trị giới hạn đề bài 
    inp << n << " " << k << '\n';

    for(int i = 1; i <= N; i++) 
        vt.pb(i);
    random_shuffle(all(vt)); //do mỗi giá trị a chỉ xuất hiện một lần 
    for(int i = 1; i <= n; i++) { // các bạn có thể sử dụng map + while
        a = vt.back();
        vt.pop_back();
        b = Rand(1, W);
        inp << a << " " << b << '\n';
    }
    vt.clear(); // do vector mình khai báo là biến toàn cụng nên phải xóa
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, b, q, k;
    n = Rand(5 * N, Q);
    if(x >= s1 + cal(50, (s2 - s1)))
        n = Q;
    if(x <= s1 + (s2 - s1) / 3.0)
        k = Rand(1, 100);
    else if(x <= s1 + 2 * (s2 - s1) / 3.0)
        k = Rand(1, n);
    else 
        k = Rand(1, W);
    inp << n << " " << k << '\n';

    M[1] = 1;
    for(int i = 1; i <= n; i++) {
        a = 1;
        while(M[a]) {
            a = Rand(W, K);
        }
            M[a] = 1;
        b = Rand(1, K);
        inp << a << " " << b << '\n';
    }
    
    M.clear();
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, b, q, k;
    n = Rand(5 * Q, W);
    if(x >= s2 + cal(50, (etest - s2)))
        n = W;
    if(x <= s2 + (etest - s2) / 3.0)
        k = Rand(1, N);
    else if(x <= s2 + 2 * (etest - s2) / 3.0)
        k = Rand(1, n);
    else 
        k = Rand(1, W);
    inp << n << " " << k << '\n';

    // vt.resize(W);
    for(int i = 1; i <= W; i++) 
        vt.pb(i);
    random_shuffle(all(vt));
    for(int i = 1; i <= n; i++) {
        a = vt.back();
        vt.pop_back();
        b = Rand(1, K);
        inp << a << " " << b << '\n';
    }
    vt.clear();
}
int main(){
    ios_base::sync_with_stdio(0);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));
    M[1] = 1;
    for (int i = btest; i <= etest; i++)
    {
        cerr << i << '\n';
        if(i <= s1)
            sub1(i);
        else if(i <= s2)
            sub2(i);
        else 
            sub3(i);
    }
    return 0;
}
