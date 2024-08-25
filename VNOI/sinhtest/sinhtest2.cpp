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
const int test_for_sub1 = 10; //% so luong test theo tung sub
const int test_for_sub2 = 30;
const int test_for_sub3 = 100;
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

    int n, k, w, l, r;
    n = Rand(5, 10);  
    k = Rand(1, n);

    inp << n << " " << k << '\n';

    vector<tuple<int, int, int>> vt;

    for(int i = 1; i <= n; i++) {
        w = Rand(1, 100);

        int t = Rand(1, 10);

        if(i == 1) 
            r = Rand(i + 1, n), l = r;
        else if(i == n) 
            l = Rand(1, i - 1), r = l;
        else {
            if(i <= 3) 
                t = Rand(2, 4);
            else if(i >= n - 3)
                t = Rand(1, 3);
                
            if(t & 1) 
                l = Rand(1, i - 1), r = l;
            else 
                r = Rand(i + 1, n), l = r;
        }

        vt.push_back({w, l, r});
    }

    // random_shuffle(all(vt));
    
    for(auto [w, l, r] : vt) 
        inp << w << " " << l << " " << r << '\n';
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n, k, w, l, r;
    n = Rand(500, 10000);  
    k = Rand(1, 100);

    inp << n << " " << k << '\n';

    vector<tuple<int, int, int>> vt;

    for(int i = 1; i <= n; i++) {
        int tt = Rand(1, 10);
        if(tt <= 3) {
            w = Rand(1, 1e6);
        }
        else 
            w = Rand(-1e6, -1);

        int t = Rand(1, 10);

        if(i == 1) 
            r = Rand(i + 1, n), l = r;
        else if(i == n) 
            l = Rand(1, i - 1), r = l;
        else {
            if(i <= 50) 
                t = Rand(2, 4);
            else if(i >= n - 50)
                t = Rand(1, 3);
                
            if(t & 1) 
                l = Rand(1, i - 1), r = l;
            else 
                r = Rand(i + 1, n), l = r;
        }

        vt.push_back({w, l, r});
    }

    // random_shuffle(all(vt));
    
    for(auto [w, l, r] : vt) 
        inp << w << " " << l << " " << r << '\n';
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    
    int n, k, w, l, r;
    n = Rand(500, 10000); 
    if(x >= s2 + cal(50, s3))
        n = 10000; 
    k = Rand(50, 100);

    inp << n << " " << k << '\n';

    vector<tuple<int, int, int>> vt;

    for(int i = 1; i <= n; i++) {
        int tt = Rand(1, 10);
        if(tt <= 3) {
            w = Rand(1, 10000000);
        }
        else 
            w = Rand(-1e6, -1);
        if(x == 90) 
            w = Rand(-1e9, -1);

        int t = Rand(1, 10);

        if(i == 1) 
            r = Rand(i + 1, n), l = Rand(i + 1, r);
        else if(i == n) 
            l = Rand(1, i - 1), r = Rand(l, i - 1);
        else {
            if(i <= 50) 
                t = Rand(2, 4);
            else if(i >= n - 50)
                t = Rand(1, 3);

            if(t & 1) 
                l = Rand(1, i - 1), r = Rand(l, i - 1);
            else 
                r = Rand(i + 1, n), l = Rand(i + 1, r);
        }

        vt.push_back({w, l, r});
    }

    // random_shuffle(all(vt));
    
    for(auto [w, l, r] : vt) 
        inp << w << " " << l << " " << r << '\n';
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
