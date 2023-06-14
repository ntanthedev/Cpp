#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, lx, ly;
struct pt {
    ll x, y;
};
pt a[N];
bool cmp(pt g, pt h){
    return g.x < h.x || (g.x == h.x && g.y < h.y);
}
void solve(){
    sort(a+1, a+1+n, cmp);
    lx = a[1].x;
    ly = a[1].y;
    ll gmax = 0;
    for(int i = 2; i <= n; i++){
        if(a[i].x <= ly){
            lx = min(a[i].x, lx);
            ly = max(a[i].y, ly);
        }
        else{
            lx = a[i].x;
            ly = a[i].y;
        }
        gmax = max(ly - lx, gmax);
    }
    cout<<gmax;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("SLINE.inp","r",stdin);
    freopen("SLINE.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].x>>a[i].y;
    }
    solve();
}