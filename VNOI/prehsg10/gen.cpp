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
const int etest = 100; // so luong test
const int test_for_sub1 = 30; //% so luong test theo tung sub
const int test_for_sub2 = 25;
const int test_for_sub3 = 25;
const int test_for_sub4 = 20;

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
    
    int n = Rand(1, 1e3), m = Rand(1, 1e3), k = Rand(1, 1e9);

    inp << n << ' ' << m << ' ' << k << '\n';

    for (int i = 1; i <= n; i++) {
        int t = Rand(1, 2);
        int x = Rand(1, 2 * (k + 1)), l = Rand(1, m), r = Rand(1, m);
        if(l > r) swap(l, r);
        inp << t << ' ';
        if(t == 1) inp << x << ' ';
        inp << l << ' ' << r << '\n';
    }
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n = Rand(1, 1e3), m = Rand(1, 1e6), k = Rand(1, 1e9);

    inp << n << ' ' << m << ' ' << k << '\n';

    vector<tuple<int, int, int, int>> vt;
    for (int i = 1; i <= n; i++) {
        int t = Rand(1, 2);
        int x = Rand(1, 2 * (k + 1)), l = Rand(1, m), r = Rand(1, m);
        if(l > r) swap(l, r);
        vt.pb({t, x, l, r});
    }

    sort(vt.begin(), vt.end(), [](tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
        return get<0>(a) < get<0>(b);
    });

    for (auto [t, x, l, r] : vt) {
        inp << t << ' ';
        if(t == 1) inp << x << ' ';
        inp << l << ' ' << r << '\n';
    }
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n = Rand(1, 1e5), m = Rand(1, 1e5), k = Rand(1, 1e9);

    inp << n << ' ' << m << ' ' << k << '\n';

    for (int i = 1; i <= n; i++) {
        int t = Rand(1, 2);
        int x = Rand(1, (k + 1)), l = Rand(1, m), r = Rand(1, m);
        if(l > r) swap(l, r);
        inp << t << ' ';
        if(t == 1) {
            inp << x << ' ';
            inp << l << ' ' << r << '\n';
        }
        else {
            inp << 1 << ' ' << m << '\n';
        }
    }
}

void sub4 (int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n = Rand(1, 1e6), m = Rand(1, 1e6), k = Rand(1, 1e9);

    inp << n << ' ' << m << ' ' << k << '\n';

    for (int i = 1; i <= n; i++) {
        int t = Rand(1, 2);
        int x = Rand(1, (k + 1)), l = Rand(1, m), r = Rand(1, m);
        if(l > r) swap(l, r);
        inp << t << ' ';
        if(t == 1) {
            inp << x << ' ';
            inp << l << ' ' << r << '\n';
        }
        else {
            inp << 1 << ' ' << m << '\n';
        }
    }
}

int main(){
    // ios_base::sync_with_stdio(false);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));

    int total_test = etest;
    int s1 = pct(test_for_sub1, total_test);
    int s2 = s1 + pct(test_for_sub2, total_test);
    int s3 = s2 + pct(test_for_sub3, total_test);

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
