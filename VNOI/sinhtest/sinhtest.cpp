#include<bits/stdc++.h>
using namespace std;
#define el inp<<'\n'
#define pb push_back
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const int btest = 1;
const int etest = 200;

ll Rand(ll l, ll h)
{
    return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (ll)rand() * (RAND_MAX + 1) +
                rand()) % (h - l + 1);
}
#define maxn 2003
//#define A 1000000000
const ll A = 1000000000000000000;
const ll H = 1000000000000;
const ll N = 1000;
const ll Q = 100000;
const ll X = 2000000000;
const ll K = 1000000000;
const ll W = 1000000;
const ll T = 10;
map<ll, ll> M;
vector<long long> vt;
void sinh(int x)
{
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = 4e3;
    for(int i = 1; i <= n; i++) {
        t = Rand(1, 13);
        a = Rand(1, 1e9);
        for(int i = 1; i <= t; i++) 
            vt.pb(a);
        if(vt.size() >= 5000)
            break;
    }
    random_shuffle(vt.begin(), vt.end());
    inp << vt.size() << '\n';
    for(auto i : vt)
        inp << i << " " ;
    vt.clear();
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = btest; i <= etest; i++)
    {
        sinh(i);
    }
    return 0;
}
