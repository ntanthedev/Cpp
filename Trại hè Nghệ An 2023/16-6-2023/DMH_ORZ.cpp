// created by Dinh Manh Hung
// tht.onepunchac168
// THPT CHUYEN HA TINH
// HA TINH, VIET NAM

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
#define task ""
#define ldb long double
#define pb push_back
#define fi first
#define se second
#define pc pop_back()
#define all(x) begin(x),end(x)
#define uniquev(v) v.resize(unique(all(v))-v.begin())
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define cntbit(v) __builtin_popcountll(v)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) ((1LL*a*b)/__gcd(a,b))
#define mask(x) (1LL<<(x))
#define readbit(x,i) ((x>>i)&1)
#define ins insert

typedef long long ll;
typedef pair <ll,ll> ii;
typedef pair <ll,ii> iii;
typedef pair <ii,ii> iiii;

ll dx[]= {1,-1,0,0,1,-1,1,-1};
ll dy[]= {0,0,-1,1,1,-1,-1,1};

const ldb PI = acos (-1);
//const ll mod=978846151;
//const ll base=29;
const int maxn=1e6+5;
const int mod=1e9+7;
const char nl = '\n';
inline int ReadInt()
{
    char co;
    for (co = getchar(); co < '0' || co > '9'; co = getchar());
    int xo = co - '0';
    for (co = getchar(); co >= '0' && co <= '9'; co = getchar())
        xo = xo * 10 + co - '0';
    return xo;
}

void WriteInt(int xo)
{
    if (xo > 9)
        WriteInt(xo / 10);
    putchar(xo % 10 + '0');
}
/* END OF TEMPLATE*/

// ================= Solution =================//
ll n,m;
const int N=2e5+5;
vector <ll> vta[N];
vector <ll> vtb[N];
ll a[N];
ll b[N];
ll ans[N];
vector <ll> divisors[N];
void optmushnpr()
{
    cin>>n>>m;
    for (int i=1;i<=2e5;i++)
    {
        for (int j=i;j<=2e5;j+=i)
        {
            divisors[j].pb(i);
        }
    }
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        vtb[a[i]].pb(i);
    }
    for (int i=1;i<=m;i++)
    {
        cin>>b[i];
        vta[b[i]].pb(i);
    }
    deque <ll> opt;
    ll pos=0;
    for (int i=1;i<=2e5;i++)
    {
        for (auto v:vta[i])
        {
            opt.pb(v);
        }
        while (!opt.empty()&&pos>0)
        {
            pos--;
            ans[opt.front()]=i;
            opt.pop_front();
        }
        if (opt.empty())
        {
            continue;
        }
        for (auto v:divisors[i])
        {
            ll pp=vtb[v].size();
            vtb[v].clear();
            while (!opt.empty()&&pp>0)
            {
                ans[opt.front()]=i;
                opt.pop_front();
                pp--;
            }
            pos+=pp;
        }
    }
    for (int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    if (fopen(task".inp","r")){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);}
    int tests;
    tests=1;
    //cin>>tests;
    while (tests--){optmushnpr();}
}

// goodbye see ya
