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
const int btest = 31; 
const int etest = 150; // so luong test
const int test_for_sub1 = 20; //% so luong test theo tung sub
const int test_for_sub2 = 30;
const int test_for_sub3 = 50;
const int s1 = double(etest) / 100.0 * test_for_sub1 * 1.0;
const int s2 = s1 + double(etest) / 100.0 * test_for_sub2 * 1.0;
const int s3 = etest - s2;


// ll Rand(ll l, ll h)
// {
//     return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                 (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
//                 (ll)rand() * (RAND_MAX + 1) +
//                 rand()) % (h - l + 1);
// }

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

int cal(int x, int n) {
    return double(n / 100.0) * x;
}

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n = Rand(1, 20);
    int k = Rand(1, n);

    inp << n << " " << k << '\n';

    for(int i = 1; i <= n; i++) {
        ll a = Rand(-K, K);
        inp << a << " ";
    }
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n = Rand(100, 2000);
    int k = Rand(1, n);

    inp << n << " " << k << '\n';

    for(int i = 1; i <= n; i++) {
        ll a = Rand(-W, W);
        if(x == 75)
            a = Rand(-5, 5);
        inp << a << " ";
    }
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    
    int n = Rand(500, 2000);
    if(x >= cal(60, s3))
        n = Rand(1800, 2000);
    int k = Rand(1, n);

    if(x >= 156)
        k = n - Rand(1, 3);

    inp << n << " " << k << '\n';

    for(int i = 1; i <= n; i++) {
        ll a = Rand(-K, K);
        if(x >= 150 && x <= 153) {
            a = Rand(-K, -K + W);
        }
        if(x == 149 || x == 148) {
            a = K;
            if(i & 1)
                a = -K;
        }

        inp << a << " ";
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
