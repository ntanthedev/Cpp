#include<bits/stdc++.h>
#define tag "tong"
#define ll long long 
const int N = 1e5+9;
using namespace std;
ll n, m, a[N], sum[4*N], leaf[N];
void build(int x, int l, int r){
    if(l == r){
        leaf[l] = x;
        sum[x] = a[l];
    }
    else{
        int mid = (l+r)/2;
        build(x*2, l, mid);
        build(x*2 + 1, mid+1, r);
        sum[x] = sum[x*2] + sum[x*2 + 1];
    }
}
void update(int u, int v){
    int x = leaf[u];
    int d = v - a[u];
    for(; x > 0; x /= 2){
        sum[x] += d;
    }
    a[u] = v;
}
int get(int x, int l, int r, int i, int j){
    if(l > j || r < i)
        return 0;
    if(i <= l && r <= j)
        return sum[x];
    int mid = (l+r)/2;
    return get(x*2, l, mid, i, j) + get(x*2+1, mid+1, r, i, j);
}
void solve(){
    char c;
    int x, y;
    cin >> c >> x >> y;
    if(c == 'C')
        update(x, y);
    else
        cout<<get(1, 1, n, x, y)<<'\n';
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while(m--)
        solve();
}