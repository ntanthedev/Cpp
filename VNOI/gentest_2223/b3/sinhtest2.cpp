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
const int test_for_sub1 = 0; //% so luong test theo tung sub
const int test_for_sub2 = 50;
const int test_for_sub3 = 100;
const int s1 = double(etest) / 100.0 * test_for_sub1 * 1.0;
const int s2 = double(etest) / 100.0 * test_for_sub2 * 1.0;
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
    assert(l <= r);
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

int cal(int x, int n) {
    return double(n / 100.0) * x;
}

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n = Rand(1, 1e3);
    int t = Rand(1, n / 2);
    int S = Rand(1e3, 1e6);
    int db = Rand(1, 5);
    vector<int> vt;

    inp << n << " " << S << '\n';

    if(S % 2 == 0 && db == 1) {
        for(int i = 1; i <= n; i++) 
            inp << S / 2 << " ";
        cout << "test " << x << '\n';
        return;
    }
    while(vt.size() < n) {
        int a = Rand(1, 1e6);
        vt.push_back(a);
        if(a < S) {
            if(t) {
                vt.push_back(S - a);
                t--;
            }
        }
    }

    random_shuffle(vt.begin(), vt.end());
    while(vt.size() > n) vt.pop_back();

    for(auto i : vt) 
        inp << i << " ";
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());

    int n = Rand(2e5, 1e6);
    int t = Rand(1, 1e4);
    int S = Rand(1e5, 1e6);
    int db = Rand(1, 5);
    vector<int> vt;

    inp << n << " " << S << '\n';
    if(S % 2 == 0 && db == 1) {
        for(int i = 1; i <= n; i++) 
            inp << S / 2 << " ";
        cout << "test " << x << '\n';
        return;
    }
    while(vt.size() < n) {
        int a = Rand(1, 1e6);
        vt.push_back(a);
        if(a < S) {
            if(t) {
                vt.push_back(S - a);
                t--;
            }
        }
    }

    random_shuffle(vt.begin(), vt.end());
    while(vt.size() > n) vt.pop_back();

    for(auto i : vt) 
        inp << i << " ";   
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    }

    return 0;
}
