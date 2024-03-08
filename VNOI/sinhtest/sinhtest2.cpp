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

void sub1(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = (x <= 20 ? Rand(1, N) : N);
    inp << n << '\n';
    f1(i, n) {
        l = Rand(1, N - 200);
        r = Rand(l+1, N);
        inp << l << " " << r << '\n';
    }
}

void sub2(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = (x <= 60 ? Rand(N, Q) : Q);
    inp << n << '\n';
    if(x == 80) {
        f1(i, n) {
            l = 1, r = 1;
            inp << l << " " << r << '\n';
        }
        return;
    }
    f1(i, n) {
        l = Rand(1, K);
        r = Rand(l + 1, l + Rand(1, 100));
        inp << l << " " << r << '\n';
    }
}

void sub3(int x) {
    ofstream os;
    ofstream inp((to_string(x) + ".inp").c_str());
    ll t, n, l, r, m, a, q, k;
    n = (x <= 90 ? Rand(Q, W) : W);
    inp << n << '\n';
    f1(i, n) {
        l = Rand(1, W - 50);
        r = Rand(l + 1, l + Rand(2, 50));
        inp << l << " " << r << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //srand(time(NULL));
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for (int i = btest; i <= etest; i++)
    {
        if(i <= 40)
            sub1(i);
        else if(i <= 80)
            sub2(i);
        else 
            sub3(i);
    }
    return 0;
}
