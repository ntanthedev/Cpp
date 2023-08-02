///code dang sai dcm
#include<bits/stdc++.h>
#define ll long long
#define xau "SCHEDULE"
#define fi first
#define se second
const int N = 1e5+9;
using namespace std;
ll n;
struct pt {
    ll a, b;
};
bool cmp(pt x, pt y){
    return x.b < y.b || (x.b == y.b && x.a > y.a);
}
pt a[N];
void solve(){
    sort(a+1, a+1+n, cmp);
    ll res = 0, day = 0;
    for(int i = 1; i <= n; i++){
        day += a[i].b;//cout<<"\nday"<<day;
        res += day*a[i].a;// cout<<" res: "<<res;
    }
    cout<<res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen(xau".inp","r")){
        freopen(xau".inp","r",stdin);
        freopen(xau".out","w",stdout);
    }
    else{
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i].a;
    for(int i = 1; i <= n; i++)
        cin >> a[i].b;
    solve();
}


