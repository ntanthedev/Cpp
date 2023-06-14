#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll n, dem = 0, ans[N], pod = 0, m;
struct pt {
    ll x, y, sl;
};
pt a[N];
bool cmp(pt c, pt d){
    return c.y < d.y || (c.y == d.y && c.x < d.x);
}
void solve(){
    for(int i = 1; i <= n; i++){
        cin >> a[i].x >> a[i].y;
        a[i].sl = 0;
    }
    sort(a+1, a+1+n, cmp);
    //ans[++pod] = a[1].y-1;
    ans[++pod] = a[1].y;
    for(int i = 2; i <= n; i++){
        if(a[i].x <= ans[pod]){
            continue;
        }
        if(a[i].x > ans[pod]){
            //ans[++pod] = a[i].y-1;
            ans[++pod] = a[i].y;
            continue;
        }
    }
    cout<<pod<<'\n';
    // for(int i = 1; i <= pod; i++)
    //     cout<<ans[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen("APC.inp", "r")){
        freopen("APC.inp","r",stdin);
        freopen("APC.out","w",stdout);
    }

    cin >> m >> n;
    cout << m << n;
    solve();
}

