//segggggggggg
#include<bits/stdc++.h>
#define tag "QUERYMIN"
#define ll long long 
const int N = 1e5+9;
using namespace std;
int a[N], n, Q;
string c;
inline int getmin(int x, int y){
    if(x == 0 && y == 0)
        return 0;
    else if(x == 0 || y == 0)
        return max(x, y);
    else
        return min(x, y);
}
struct SegmentTree {
    //build seggggg
    int L[4*N], R[4*N], lmin[4*N], leaf[N];
    void build(int x, int l, int r){
        L[x] = l, R[x] = r;
        lmin[x] = 0;
        if(l == r){
            leaf[l] = x;
        }
        else{
            int mid = (l+r)/2;
            build(x<<1, l, mid);
            build((x<<1)+1, mid+1, r);
            //lmin[x] = min(lmin[x<<1], lmin[(x<<1)+1]);
        }
    }
    void update(int k, int w){
        int x = leaf[k];
        lmin[x] = max(w, 0);
        for(x = x/2; x > 0; x >>= 1){
            lmin[x] = getmin(lmin[x<<1], lmin[(x<<1)+1]);
        }
        a[k] = w;
    }
    int qi, qj;//stupid, why i use it for my code ???
    int get(int x){
        return lmin[x];//we have a bug here !!!
    }
} Tree;
void solve(){
    int x, y;
    memset(a, 0 , sizeof(a));
    Tree.build(1, 1, n);
    while(Q--){
        cin >> c;
        if(c == "AGN"){
            cin >> x >> y;
            Tree.update(x, y);
        }
        else
            cout<<Tree.lmin[1]<<'\n';
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> Q;
    solve();
}
//pleassss, no bug :<