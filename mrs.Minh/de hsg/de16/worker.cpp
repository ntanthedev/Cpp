#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
struct pt{
    ll x, y;
};
ll n, m, max1 = -1, max2 = -1, vt1, vt2;
pt a[N];
bool cmp(pt g, pt h){
    return (g.x < h.x || (g.x == h.x && g.y < h.y));
}
void solve(){
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i < n; i++){
        if(a[i].y > a[i+1].x){
            if(a[i].y > a[i+1].y){
                a[i+1].x = a[i].x;
                a[i+1].y = a[i].y;
            }
            else
                a[i+1].x = a[i].y+1;
        }
        if(a[i].y - a[i].x > max2){
            max2 = a[i].y - a[i].x;
            vt2 = i;
        }
    }
    cout<<vt1<<'\n'<<vt2;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("worker.inp","r",stdin);
    freopen("worker.out","w",stdout);
    cin>>m>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].x>>a[i].y;
        if(a[i].y - a[i].x > max1){
            max1 = a[i].y - a[i].x;
            vt1 = i;
        }
    }
    solve();
}