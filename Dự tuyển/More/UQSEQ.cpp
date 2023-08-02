#include<bits/stdc++.h>
#define tag "UQSEQ"
#define ll long long 
const int N = 1e5+9;
using namespace std;
int Q, n, a[N];

struct pt{
    int val, lazy;
};
pt tree[4*N];
void build(int x, int l, int r){
    //tree[x].val = 0;
    if(l == r)
        tree[x].val = a[l];
    else{
        int mid = (l+r)/2;
        build(x*2, l, mid);
        build(x*2 + 1, mid+1, r);
        tree[x].val = max(tree[x*2].val, tree[x*2+1].val);
    }
}
void down(int x){
    int t = tree[x].lazy;
    tree[x*2].lazy += t;
    tree[x*2].val += t;
    
    tree[x*2+1].lazy += t;
    tree[x*2+1].val += t;

    tree[x].lazy = 0;
}
void update(int x, int l, int r, int i, int j, int k){
    if(r < i || l > j)
        return;
    if(i <= l && r <= j){
        tree[x].val += k;
        tree[x].lazy += k;
        return;
    }
    int mid = (l+r)/2;
    down(x);
    update(x*2, l, mid, i, j, k);
    update(x*2 + 1, mid+1, r, i, j, k);
    tree[x].val = tree[x*2].val + tree[x*2+1].val;
}
int get(int x, int l, int r, int i, int j){
    if(l > i || r < j)
        return 0;
    if(i <= l && r <= j){
        return tree[x].val;
    }
    int mid = (l+r)/2;
    down(x);
    return get(x*2, l, mid, i, j) + get(x*2+1, mid+1, r, i, j);
}
void solve(){
    int x, y, k;
    char c;
    cin >> c;
    if(c == 'I'){
        cin >> x >> y >> k;
        update(1, 1, n, x, y, k);
    }
    else{
        cin >> x;
        cout<<get(1, 1, n, x, x)<<'\n';
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    memset(a, 0, sizeof(a));
    //build(1, 1, n);
    cin >> n >> Q;
    while(Q--)
        solve();
}
int read(){
    bool neg = false;
    char c = getchar();
    for(; c < '0' || '9' < c; c = getchar())
        if(c == '-') neg = !neg;
    int value =  0;
    while('0' <= c && c <= '9')
        value = (value << 3) + (value << 1) + c - '0', c = getchar();
    return neg ? value : -value;
}