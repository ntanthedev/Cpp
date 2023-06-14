#include<bits/stdc++.h>
#define ll long long
#define xau "QUERYSUM"
const int N = 1e5+9;
using namespace std;
int n, a[N], Q;

struct SegmentTree{
    int L[4*N], H[4*N], leaf[N];
    ll sum[N];
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
        request(1);
    }
} tree;
void solve(){
    char c; ll x, y;
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
