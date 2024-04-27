#include<bits/stdc++.h>
using namespace std;
#define el inp<<'\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define	f0(i,n) for(int i=0;i<n;i++)
#define f1(i,n) for(int i=1;i<=n;i++)
typedef long long ll;
const int btest = 1;
const int etest = 100;

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
void sinh(int x)
{
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, b, c, q, k;
    n = Rand(Q, 2 * Q), q = Rand(Q, 2 * Q);
    inp << n << " " << q << '\n';
    vt.clear();
    for(int i = 1; i <= n; i++)  {
        a = Rand(1, K);
        inp << a << " ";
        vt.pb(a);
    }

    while(q--) {
        t = Rand(1, 4);
        if(t % 2 == 1) {
            random_shuffle(all(vt));
            inp << vt.front() << '\n';
        }
        else 
            inp << Rand(1, K) << '\n';
    }
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
