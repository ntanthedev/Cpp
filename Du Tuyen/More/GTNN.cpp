#include<bits/stdc++.h>
#define tag "GTNN"
#define ll long long 
const int N = 1e5+9;
using namespace std;
ll n, a[N], Q, lmin[4*N];
void build(int x, int l, int r){
    if(l == r){
        lmin[x] = a[l];
    }
    else{
        int mid = (l+r)/2;
        build(x<<1, l, mid);
        build((x<<1)+1, mid+1, r);
        lmin[x] = min(lmin[x<<1], lmin[(x<<1)+1]);
    }
}
int get(int x, int l, int r, int i, int j){
    if(l > j || r < i)
        return INT_MAX;
    if(i <= l && r <= j)
        return lmin[x];
    int mid = (l+r)/2;
    return min(get(x<<1, l, mid, i, j), get((x<<1)+1, mid+1, r, i, j));
}
void solve(){
    ll x, y;
    cin >> x >> y;
    cout<<get(1, 1, n, x, y)<<'\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> Q;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    //for(int i = 1; i <= 4*n; i++)
        //cout<<lmin[i]<<" ";
    //build(1, 1, n);
    while(Q--)
        solve();
}