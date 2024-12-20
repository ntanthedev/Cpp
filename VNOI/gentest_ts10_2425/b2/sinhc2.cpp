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

mt19937_64 rd(static_cast<unsigned int>(std::time(nullptr)));
ll Rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l,r) (rd);
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


void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, b, q, k;
    n = Rand(1, N);
    if(x >= 50) n = N;
    inp << n << '\n';
    for(int i = 1; i <= n; i++) {
        a = Rand(1, N);
        if(x == 60)
            a = 1;
        if(x == 61)
            a = 1;
        inp << a << ' ';
    }
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = Rand(1, N);
    if(x >= 80) n = N;
    inp << n << '\n';
    for(int i = 1; i <= n; i++) {
        a = Rand(5*Q, W);
        inp << a << ' ';
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
        if(i <= 70)
            sub1(i);
        else if(i <= 70 + 15)
            sub2(i);
        else 
            sub3(i);
    }
    return 0;
}
