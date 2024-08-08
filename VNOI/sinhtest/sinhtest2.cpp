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
const int etest = 200; // so luong test
const int test_for_sub1 = 50; //% so luong test theo tung sub
const int test_for_sub2 = 50;
const int test_for_sub3 = 40;
const int s1 = double(etest) / 100.0 * test_for_sub1 * 1.0;
const int s2 = double(etest) / 100.0 * test_for_sub2 * 1.0;


ll Rand(ll l, ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}

int Randd(int l, int r) {
    return uniform_int_distribution<int>(l,r) (rd);
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
mt19937 rd(static_cast<unsigned int>(std::time(nullptr)));

int cal(int x, int n) {
    return double(n / 100.0) * x;
}

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, b, q, k;
    
    t = Rand(1, Q);
    if(x >= cal(75, s1))
        t = Rand(Q - 100, Q);
    inp << t << '\n';
    while(t--) {
        a = Rand(1, Q);
        ll tt = rd() % 10;
        if(tt % 3 == 0)
            a = Rand(1, W);
        b = Rand(a, W);
        inp << a << " " << b << '\n';
    }
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k, b;
    
    t = Rand(1, Q);
    if(x >= cal(75, s1))
        t = Rand(Q - 100, Q);
    inp << t << '\n';
    while(t--) {
        a = Rand(1, 1e8);
        ll tt = rd() % 10;
        if(tt % 3 == 0)
            a = Rand(1, K - 100);
        b = Rand(a, K);
        if(Rand(1, 20) % 10 == 1) 
            b = a;
        inp << a << " " << b << '\n';
    }

}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, b, q, k;
    n = Rand(Q, W);
    if(x >= 90) n = W;
    inp << n << '\n';
    for(int i = 1; i <= n; i++) {
        a = Rand(1, W);
        inp << a << ' ';
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));
    M[1] = 1;
    for (int i = btest; i <= etest; i++)
    {
        if(i <= s1)
            sub1(i);
        else if(i <= s2)
            sub2(i);
        else 
            sub3(i);
    }
    return 0;
}
