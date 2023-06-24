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

const int N=1e5+5;
ll a[N],V;
ll n;

void optmushnpr()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cin>>V;
    ll res=a[1];
    ll dem=1;
    ll kq=LLONG_MAX;
    for (int i=1;i<=n;i++)
    {
        if (i!=n)
        {
            ll pa=V-res;
            pa/=a[i];
            if (pa*a[i]<V-res)
            {
                pa++;
            }
            kq=min(kq,pa+dem);
            if (res<a[i+1]-1)
            {
                ll pp=a[i+1]-res-1;
                pp/=a[i];
                if (pp*a[i]<a[i+1]-res-1)
                {
                    pp++;
                }
                res+=pp*a[i];
                dem+=pp;
            }
        }
        else
        {
            ll pa=V-res;
            pa/=a[i];
            if (pa*a[i]<V-res)
            {
                pa++;
            }
            kq=min(kq,pa+dem);
        }
    }
    cout<<kq;
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
