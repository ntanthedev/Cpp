// created by Dinh Manh Hung
// tht.onepunchac168
// THPT CHUYEN HA TINH
// HA TINH, VIET NAM

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define task "code"
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
ll n,l,r;
const int N=2e5+5;
ll w[N];
bool dp[85][100005];
ll trade[85][100005];
ii a[N];
ll sum[N];
void optmushnpr()
{
    cin>>n>>l>>r;
    for (int i=1;i<=n;i++)
    {
        cin>>w[i];
        a[i].fi=w[i];
        a[i].se=i;
    }
    if (n<=40)
    {
        vector <ii> vta,vtb;
        ll aa=n/2;
        for (int i=0;i<mask(aa);i++)
        {
            ll sum=0;
            for (int j=0;j<aa;j++)
            {
                if (readbit(i,j)==1)
                {
                    sum+=w[j+1];
                }
            }
            vta.pb({sum,i});
        }
        ll bb=n-aa;
        for (int i=0;i<mask(bb);i++)
        {
            ll sum=0;
            for (int j=0;j<bb;j++)
            {
                if (readbit(i,j)==1)
                {
                    sum+=w[j+aa+1];
                }
            }
            vtb.pb({sum,i});
        }
        sort(vtb.begin(),vtb.end());
        for (auto v:vta)
        {
            if (vtb.back().fi+v.fi>=l)
            {
                ii tmp={l-v.fi,0};
                ii a1=*lower_bound(vtb.begin(),vtb.end(),tmp);
                if (a1.fi+v.fi<=r)
                {
                    vector <ll> ans;
                    for (int i=0;i<aa;i++)
                    {
                        if (readbit(v.se,i)==1)
                        {
                            ans.pb(i+1);
                        }
                    }
                    for (int i=0;i<bb;i++)
                    {
                        if (readbit(a1.se,i)==1)
                        {
                            ans.pb(i+aa+1);
                        }
                    }
                    cout<<ans.size()<<nl;
                    for (auto v:ans)
                    {
                        cout<<v<<' ';
                    }
                    return;
                }
            }
        }
    }
    else if (n<=80)
    {
        dp[0][0]=1;
        for (int i=1;i<=n;i++)
        {
            for (int j=0;j<=r-w[i];j++)
            {
                if (dp[i-1][j]==1)
                {
                    dp[i][j+w[i]]=1;
                    trade[i][j+w[i]]=i;
                }
            }
            for (int j=0;j<=r;j++)
            {
                if (dp[i-1][j]==1)
                {
                    dp[i][j]=1;
                    trade[i][j]=trade[i-1][j];
                }
            }
        }
        ll opt=-1;
        for (int i=l;i<=r;i++)
        {
            if (dp[n][i]==1)
            {
                opt=i;
                break;
            }
        }
        assert(opt!=-1);
        ll id=n;
        vector <ll> ans;
        while (true)
        {
            if (opt==0){break;}
            if (trade[id][opt]!=id)
            {
                id--;
            }
            else
            {
                ans.pb(id);
                opt-=w[id];
            }
        }
        cout<<ans.size()<<nl;
        while (!ans.empty())
        {
            cout<<ans.back()<<' ';
            ans.pop_back();
        }

    }
    else
    {
        bool checka=true;
        bool checkb=true;
        for (int i=2;i<=n;i++)
        {
            if (w[i]!=w[i-1])
            {
                checka=false;
            }
        }
        for (int i=1;i<=n;i++)
        {
            if (w[i]!=i)
            {
                checkb=false;
            }
        }
        if (checka==true||checkb==true)
        {
            sort(a+1,a+n+1);
            vector <ll> ans;
            ll sum=0;
            for (int i=n;i>=1;i--)
            {
                if (sum+a[i].fi<=r)
                {
                    sum+=a[i].fi;
                    ans.pb(a[i].se);
                }
            }
            sort(ans.begin(),ans.end());
            cout<<ans.size()<<nl;
            for (auto v:ans)
            {
                cout<<v<<' ';
            }
        }
        else
        {
            ll gg=LLONG_MAX;
            ll ga=LONG_MIN;
            for (int i=1;i<=n;i++)
            {
                gg=min(gg,a[i].fi);
                ga=max(ga,a[i].fi);
            }
            assert(ga-gg<=r-l);
            sort (a+1,a+n+1);
            ll ss=0;
            ll id=1;
            vector <ll> ans;
            for (int i=1;i<=n;i++)
            {
                ss+=a[i].fi;
                while (id<=i&&ss>r)
                {
                    ss-=a[id].fi;
                    id++;
                }
                if (ss>=l&&id<=i)
                {
                    for (int j=id;j<=i;j++)
                    {
                        ans.pb(a[j].se);
                    }
                    break;
                }
            }
            if (ans.empty())
            {
                cout<<-1;return;
            }
            sort(ans.begin(),ans.end());
            cout<<ans.size()<<nl;
            for (auto v:ans)
            {
                cout<<v<<' ';
            }
        }
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
