#include<bits/stdc++.h>
using namespace std;
#define el inp<<'\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const int btest = 1;
const int etest = 500;

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

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = Rand(1, N), m = Rand(1, N);
    inp << n << " " << m << '\n';
    for(int i = 1; i <= n; i++) 
        inp << Rand(1, N) << " " ;
    inp << '\n';
    for(int i = 1; i <= m; i++)
        inp << Rand(1, N) << " " ;
    inp << '\n';
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = Rand(5*N, Q); k = Rand(1, n + 10);
    inp << n << " " << k << '\n';
    f1(i, n) {
        a = Rand(1, W);
        inp << a << " ";
    }
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = N, m = N;
    inp << n << " " << m << '\n';
    for(int i = 1; i <= n; i++) 
        inp << Rand(1, W) << " " ;
    inp << '\n';
    for(int i = 1; i <= m; i++)
        inp << Rand(1, W) << " " ;
    inp << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = btest; i <= etest; i++)
    {
        if(i <= 100)
            sub1(i);
        // else if(i <= 60)
        //     sub2(i);
        else 
            sub3(i);
    }
    return 0;
}
