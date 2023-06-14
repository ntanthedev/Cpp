#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, ans = 0, L, R;
queue<int>q;
struct pt{
    ll d, c, vt;
};
pt a[N];
bool cmp(pt x, pt y){
    return x.d < y.d || (x.d == y.d && x.c < y.c);
}
void solve(){
    sort(a+1, a+1+n, cmp);
    for(int i = 2; i <= n; i++){
        if(a[i].d >= R){
            R = a[i].c;
            q.push(a[i].vt);
        }
    }
    cout<<q.size()<<'\n';
    while(!q.empty()){
        cout<<q.front()<<'\n';
        q.pop();
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //freopen("ACT21.inp","r",stdin);
    //freopen("ACT21.out","w",stdout);
    freopen("a.inp","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].d>>a[i].c;
        a[i].vt = i;
    }
    solve();
}