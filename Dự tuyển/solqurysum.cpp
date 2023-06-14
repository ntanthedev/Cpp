#define taskname "QUERYSUM"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long lli;
const int maxN = 1e5 + 1;
int n, m, salary[maxN];
struct TSegmentTree
{
    int L[4 * maxN], H[4 * maxN];
    lli sum[4 * maxN];
    int leaf[maxN];
    void Build(int x, int low, int high)
    {
        L[x] = low; H[x] = high;
        sum[x] = 0;
        if (low == high)
            leaf[low] = x;
        else
        {
            int middle = (low + high) / 2;
            Build(x << 1, low, middle);
            Build((x << 1) + 1, middle + 1, high);
        }
    }
    void Update(int k, int w)
    {
        int delta = w - salary[k];
        int x = leaf[k];
        for (; x > 0; x >>= 1)
            sum[x] += delta;
        salary[k] = w;
    }
    int qi, qj;
    lli Request(int x)
    {
        if (L[x] > qj || H[x] < qi) return 0;
        if (qi <= L[x] && H[x] <= qj) return sum[x];
        return Request(x << 1) + Request((x << 1) + 1);
    }
    lli Query(int i, int j)
    {
        qi = i; qj = j;
        return Request(1);
    }
} tree;

void Enter()
{
    cin >> n >> m;
    fill_n(salary + 1, n, 0);
    tree.Build(1, 1, n);
}

void Solve()
{
    for (; m > 0; --m)
    {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'S') tree.Update(i, j);
        else cout << tree.Query(i, j) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Solve();
}

/*
#include<bits/stdc++.h>
#define ll long long
#define xau "QUERYSUM"
const int N = 1e5+9;
using namespace std;
int n, a[N], Q;

struct SegmentTree{
    int L[4*N], H[4*N], leaf[N];
    ll sum[4*N];
    void build(int x, int l, int h){
        L[x] = l; H[x] = h;
        sum[x] = 0;
        if(l == h)
            leaf[l] = x;
        else{
            int mid = (l+h)/2;
            build(x << 1, l, mid);
            build((x << 1) + 1, mid+1, h);
        }
    }
    void update(int k, int w){
        int d = w - a[k];
        int x = leaf[k];
        for(; x > 0; x >>= 1)
            sum[x] += d;
        a[k] = w;
    }
    int qi, qj;
    ll request(int x){
        if(L[x] > qj || H[x] < qi)
            return 0;
        if(qi <= L[x] && H[x] <= qj)
            return sum[x];
        return request(x << 1) + request((x << 1) + 1);
    }
    ll Query(int i, int j){
        qi = i; qj = j;
        return request(1);
    }
} tree;
void solve(){
    char c; int x, y;
    while(Q--){
        cin >> c >> x >> y;
        if(c == 'S')
            tree.update(x, y);
        else
            cout<<tree.Query(x, y)<<'\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n >> Q;
    memset(a, 0, sizeof(a));
    tree.build(1, 1, n);
    solve();
}

*/
