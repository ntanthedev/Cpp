// created by Dinh Manh Hung
// onepunchac168
// THPT CHUYEN HA TINH
// HA TINH, VIET NAM
// Master go go

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
//#pragma GCC target("sse4,avx2,fma")
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
const int N=3e5+5;

int n;
ll a[N];

struct Node {
	ll sum;
	ll max1;
	ll max2;
	ll maxc;
	ll lazy;
} T[N * 4];

ll orz=0;

void mergea(int node) {
	T[node].sum = T[node *2].sum + T[node *2 +1].sum;
	if (T[node *2].max1 == T[node *2 +1].max1) {
		T[node].max1 = T[node *2].max1;
		T[node].max2 = max(T[node *2].max2, T[node *2 +1].max2);
		T[node].maxc = T[node *2].maxc + T[node *2 +1].maxc;
	} else {
		if (T[node *2].max1 > T[node *2 +1].max1) {
			T[node].max1 = T[node *2].max1;
			T[node].max2 = max(T[node *2].max2, T[node *2 +1].max1);
			T[node].maxc = T[node *2].maxc;
		} else {
			T[node].max1 = T[node *2 +1].max1;
			T[node].max2 = max(T[node *2].max1, T[node *2 +1].max2);
			T[node].maxc = T[node *2 +1].maxc;
		}
	}
}

void add(int node, int tl, int tr, ll v) {
	if (v == 0) { return; }
	T[node].sum += (tr - tl + 1) * v;
	T[node].max1 += v;
	if (T[node].max2 != -1e9-5) { T[node].max2 += v; }
}

void push_max(int node, ll v, bool l) {
	if (v >= T[node].max1) { return; }
	T[node].sum -= T[node].max1 * T[node].maxc;
	T[node].max1 = v;
	T[node].sum += T[node].max1 * T[node].maxc;
}
ll push_max2(int node, ll v, bool l){
    ll opt=T[node].sum;
	if (v >= T[node].max1) { return opt; }
	opt -= T[node].max1 * T[node].maxc;
	opt += v * T[node].maxc;
	return opt;
}


void pushdown(int node, int tl, int tr) {
	if (tl == tr) return;
	int tm = (tl + tr) >> 1;
	add(node *2, tl, tm, T[node].lazy);
	add(node *2 +1, tm + 1, tr, T[node].lazy);
	T[node].lazy = 0;
	push_max(node *2, T[node].max1, tl == tm);
	push_max(node *2 +1, T[node].max1, tm + 1 == tr);
}

void build(int node = 1, int tl = 0, int tr = n - 1) {
	T[node].lazy = 0;
	if (tl == tr) {
		T[node].sum = T[node].max1 = a[tl];
		T[node].maxc = 1;
		T[node].max2 = -1e9-5;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(node *2, tl, tm);
	build(node *2 +1, tm + 1, tr);
	mergea(node);
}

void update_add(int l, int r, ll v, int node = 1, int tl = 0, int tr = n - 1) {
	if (r < tl || tr < l) { return; }
	if (l <= tl && tr <= r) {
		add(node, tl, tr, v);
		return;
	}
	pushdown(node, tl, tr);

	int tm = (tl + tr) >> 1;
	update_add(l, r, v, node *2, tl, tm);
	update_add(l, r, v, node *2 +1, tm + 1, tr);
	mergea(node);
}

void update_min(int l, int r, ll v, int node = 1, int tl = 0, int tr = n - 1) {
	if (r < tl || tr < l || v >= T[node].max1) { return; }
	if (l <= tl && tr <= r && v > T[node].max2) {
		push_max(node, v, tl == tr);
		return;
	}
	pushdown(node, tl, tr);

	int tm = (tl + tr) >> 1;
	update_min(l, r, v, node *2, tl, tm);
	update_min(l, r, v, node *2 +1, tm + 1, tr);
	mergea(node);
}

ll query_sum(int l, int r, int node = 1, int tl = 0, int tr = n - 1) {
	if (r < tl || tr < l) { return 0; }
	if (l <= tl && tr <= r) { return T[node].sum; }
	pushdown(node, tl, tr);

	int tm = (tl + tr) >> 1;
	return query_sum(l, r, node *2, tl, tm)+query_sum(l, r, node *2 +1, tm + 1, tr);
}
ii query_max(int l, int r, int node = 1, int tl = 0, int tr = n - 1) {
	if (r < tl || tr < l) { return {0,0}; }
	if (l <= tl && tr <= r) { return {T[node].max1,T[node].maxc}; }
	pushdown(node, tl, tr);
	int tm = (tl + tr) >> 1;
	ii aa=query_max(l, r, node *2, tl, tm);
	ii bb=query_max(l, r, node *2 +1, tm + 1, tr);
	if (aa.fi==bb.fi)
    {
        return {aa.fi,aa.se+bb.se};
    }
    if (aa.fi>bb.fi)
    {
        return {aa.fi,aa.se};
    }
    return {bb.fi,bb.se};
}
ll query_max2(int l, int r,ll val, int node = 1, int tl = 0, int tr = n - 1) {
	if (r < tl || tr < l) { return -1e9-5; }
	if (l <= tl && tr <= r) {
        if (T[node].max1!=val)
        {
            return T[node].max1;
        }
        if (T[node].max2!=val)
        {
            return T[node].max2;
        }
        return -1e9-5;
	}
	pushdown(node, tl, tr);
	int tm = (tl + tr) >> 1;
	ll aa=query_max2(l, r,val, node *2, tl, tm);
	ll bb=query_max2(l, r,val, node *2 +1, tm + 1, tr);
	return max(aa,bb);
}
ll query_max3(int l, int r,ll val, int node = 1, int tl = 0, int tr = n - 1) {
	if (r < tl || tr < l) { return 0; }
	if (l <= tl && tr <= r) {
        if (T[node].max1==val)
        {
            return T[node].maxc;
        }
        return 0;
	}
	pushdown(node, tl, tr);
	int tm = (tl + tr) >> 1;
	ll aa=query_max3(l, r, val,node *2, tl, tm);
	ll bb=query_max3(l, r, val,node *2 +1, tm + 1, tr);
	return aa+bb;
}
void update_opt(int i, long long v, int node = 1, int tl = 0, int tr = n-1){
    if (tr<i||tl>i)
    {
        return;
    }
	if (tl == tr) {
        T[node].sum=v;
        T[node].max1=v;
        T[node].max2=-1e9-5;
        T[node].maxc=1;
		return;
	}
	pushdown(node,tl,tr);
	int tm = (tl + tr) / 2;
    update_opt(i, v, node * 2, tl, tm);
    update_opt(i, v, node * 2 + 1, tm + 1, tr);
	mergea(node);
}
ll q;
void optmushnpr(){
    cin>>n>>q;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build();
    while (q--)
    {
        ll aa;
        cin>>aa;
        if (aa==1)
        {
            ll l,r,k;
            cin>>l>>r>>k;
            l--;r--;
            if (query_sum(l,r)<=k)
            {
                update_min(l,r,0);
                continue;
            }
            while (true)
            {
                if (k==0)
                {
                    break;
                }
                ii pp=query_max(l,r);
                ll cnt=max(0*1LL,query_max2(l,r,pp.fi));
                if ((pp.fi-cnt)*pp.se<=k)
                {
                    k-=(pp.fi-cnt)*pp.se;
                    update_min(l,r,cnt);
                }
                else
                {
                    ll bb=pp.fi*pp.se-k;
                    ll cc=bb/pp.se;
                    if (cc*pp.se<bb){cc++;}
                    k-=(pp.fi-cc)*pp.se;
                    update_min(l,r,cc);
                    if (k>0)
                    {
                        ll left=l;
                        ll right=r;
                        ll ans;
                        while (left<=right)
                        {
                            ll mid=(left+right)/2;
                            if (query_max3(l,mid,cc)<=k)
                            {
                                ans=mid;
                                left=mid+1;
                            }
                            else right=mid-1;
                        }
                        update_min(l,ans,cc-1);
                    }
                    k=0;
                }
            }
        }
        else if (aa==2)
        {
            ll id,x;
            cin>>id>>x;
            id--;
            update_opt(id,x);
        }
        else
        {
            ll l,r;
            cin>>l>>r;
            l--;r--;
            cout<<query_sum(l,r)<<nl;

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
    int tt;
    tt=1;
    //cin>>t;
    while (tt--){optmushnpr();}
}

// goodbye see ya
