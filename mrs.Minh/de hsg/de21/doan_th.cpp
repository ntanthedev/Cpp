#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n;
struct pt
{
    ll vt, d, c;
};
pt a[N];
bool cmp(pt x, pt y){
    return x.d < y.d || (x.d == y.d && x.c < y.c);
}
void solve(){   
    ll  x, y; cin>>x>>y; 
    for(int i = 1; i <= n; i++){
        cin>>a[i].d>>a[i].c;
        a[i].vt = i;
    }
    sort(a+1, a+1+n, cmp);
    ll ans = 0, ld, lc;
    vector<int> q;
    for(int i = n; i >= 1; i--){
        if(a[i].d <= x){
            ld = a[i].d;
            lc = a[i].c;
            q.push_back(a[i].vt);
            break;
        }
    }
    while(lc < y){
        for(int i = n; i >= 1; i--){
            if(a[i].d <= lc && a[i].c > lc){
                lc = a[i].c;
                q.push_back(a[i].vt);
            }
        }
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("doan_th.inp","r",stdin);
    //freopen("doan_th.out","w",stdout);
    cin>>n;
    solve();
}