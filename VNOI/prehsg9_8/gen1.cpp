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
const int test_for_sub1 = 50; //% so luong test theo tung sub
const int test_for_sub2 = 50;
const int test_for_sub3 = 100;
const int s1 = double(etest) / 100.0 * test_for_sub1 * 1.0;
const int s2 = double(etest) / 100.0 * test_for_sub2 * 1.0;
const int s3 = etest - s2;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll Rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l,r) (rd);
} 

const ll A = 1e18;
const ll H = 1e12;
const ll N = 1e3;
const ll Q = 1e5;
const ll X = 2e9;
const ll K = 1e9;
const ll W = 1e6;
const ll T = 10;

int pct(int x, int n) {
    return double(n / 100.0) * x;
}

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    int n, k;
    n = Rand(1, N);
    k = Rand(1, n);
    if(x <= 12)
        k = Rand(1, min(n, 100));
    if(x == 2) {
        n = 1;
        k = 1;
    }
    if(x == 3) 
        k = 1;
    if(x == 25)
        k = n;
    inp << n << ' ' << k;
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n, k;
    n = Rand(5e5, 1e6);
    k = Rand(1, n);
    if(x <= 40)
        k = Rand(1, min(n, 500));
    if(x == 27) 
        k = 1;
    if(x == 50)
        k = n;
    inp << n << ' ' << k;
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

}
int main(){
    // ios_base::sync_with_stdio(false);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = btest; i <= etest; i++)
    {
        if(i <= s1)
            sub1(i);
        else if(i <= s1 + s2)
            sub2(i);
        else 
            sub3(i);
        cerr << "test " << i << '\n';
    }

    return 0;
}
