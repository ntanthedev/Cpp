#include<bits/stdc++.h>
#define tag "FIND"
#define ll long long 
const int N = 1e5+9;
using namespace std;
int Q, n, a[N], leaf[N], lmax[4*N];

void build(int x, int l, int r){
    lmax[x] = 0;
    if(l == r)
        leaf[l] = x;
    else{
        int mid = (l+r)/2;
        build(x<<1, l, mid);
        build((x<<1)+1, mid+1, r);
    }
}
void update(int u, int v){
    int x = leaf[u];
    a[u] = v;
    lmax[x] = v;
    for(x = x/2; x > 0; x >>= 1){
        lmax[x] = max(lmax[x<<1], lmax[(x<<1)+1]);
    }
}
int Query(int x, int l, int r, int i, int j){
    if(l > j || r < i)
        return INT_MIN;
    if(i <= l && r <= j)
        return lmax[x];
    int mid = (l+r)/2;
    return max(Query(x<<1, l, mid, i, j), Query((x<<1)+1, mid+1, r, i, j));
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    memset(a, 0, sizeof(a));
    cin >> n >> Q;    
    build(1, 1, n);
    for(int i = 1; i <= Q; i++){
        int c, x, y;
        cin >> c >> x >> y;
        if(c == 1)
            update(x, y);
        else
            cout<<Query(1, 1, n, x, y)<<'\n';
    }
}