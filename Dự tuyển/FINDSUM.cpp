#include<bits/stdc++.h>
#define tag "FINDSUM"
#define ll long long 
const int N = 5e5+9;
using namespace std;
ll lazy[4*N], n, sum[4*N], a[N], Q;
void update(int x, int l, int r, int i, int j, int k){
    if(lazy[x] != 0){
        sum[x] += (r-l+1)*lazy[x];
        if(l != r){
            lazy[x*2] += lazy[x];
            lazy[x*2+1] += lazy[x];
        }
        lazy[x] = 0;
    }
    if(l > j || r < i)
        return;
    if(i <= l && r <= j){
        sum[x] += (r-l+1)*k;
        if(l != r){
            lazy[x*2] += k;
            lazy[x*2+1] += k;
        }
        return;
    }
    int mid = (l+r)/2;
    update(x*2, l, mid, i, j, k);
    update(x*2 + 1, mid+1, r, i, j, k);
    sum[x] = sum[x*2] + sum[x*2+1];
}
int query(int x, int l, int r, int i, int j){
    if(lazy[x] != 0){
        sum[x] += lazy[x]*(r-l+1);
        if(l != r){
            lazy[x*2] += lazy[x];
            lazy[x*2+1] += lazy[x];
        }
        lazy[x] = 0;
    }
    if(l > j || r < i)
        return 0;
    if(i <= l && r <= j){
        return sum[x];
    }
    int mid = (l+r)/2;
    
    return query(x*2, l, mid, i, j) + query(x*2+1, mid+1, r, i, j);
}
void solve(){
    ll c, x, y, z;
    cin >> c;
    if(c == 0){
        cin >> x >> y >> z;
        update(1, 1, n, x, y, z);
    }
    else{
        cin >> x >> y;
        cout<<query(1, 1, n, x, y)<<'\n';
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    memset(lazy, 0, sizeof(lazy));
    cin >> n >> Q;
    while(Q--)
        solve();
}