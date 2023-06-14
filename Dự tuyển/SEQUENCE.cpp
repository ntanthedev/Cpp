#include<bits/stdc++.h>
#define tag "SEQUENCE"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll n, sl[4*N], a[N], ucln[4*N], leaf[N], Q, ans;
void sub1(){
    while(Q--){
        int c; cin >> c;
        if(c == 1){
            int u, v; cin >> u >> v;
            a[u] = v;
        }
        else{
            ans = 0;
            int l, r;
            cin >> l >> r;
            for(int i = l; i <= r; i++){
                ll s = a[i];
                if(a[i] > 1) 
                    ans++;
                for(int j = i+1; j <= r; j++){
                    int t = __gcd(s, a[j]); 
                    if(t > 1)
                        ans++;
                    else
                        break;
                }
            }
        cout<<ans<<'\n';
        }
    }
}
void build(int x, int l, int r){
    if(l == r){
        leaf[l] = x;
        ucln[x] = a[l];
        if(a[l] == 1)
            sl[x] = 0;
    }
    else{
        int mid = (l+r)/2;
        build(x*2, l, mid);
        build(x*2+1, mid+1, r);
        ucln[x] = gcd(ucln[x*2], ucln[x*2+1]);
        if(ucln[x] != 1)
            sl[x]++;
    }
}
void update(int v, int w){
    int x = leaf[v];
    ucln[x] = w;
    for(x /= 2; x > 0; x /= 2){
        ucln[x] = __gcd(ucln[x*2], ucln[x*2+1]);
    }
    a[v] = w;
}
int get(int x, int l, int r, int i, int j){

}
void sub2(){

}
void solve(){
    if(n <= 500 && Q <= 100)
        sub1();
    else
        sub2();
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    memset(sl, 0, sizeof(sl));
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    solve();
}