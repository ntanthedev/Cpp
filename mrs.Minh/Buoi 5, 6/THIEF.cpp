#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long N = 1e6+9;
ll res, sl, n, m;
struct pt{
    ll a, b;
};
pt x[N], kq[N];
void ip(){
    cin>>n>>m;
    for(int i = 1; i <= m; i++){
        cin>>x[i].a>>x[i].b;
    }
}
bool cmp(ll x, ll y){
    return (x.b > y.b);
}
void slove(){
    res = 0; sl = 0;
    for(int i = 1; i <= m; i++){
        if(n >= x[i].a){
            res += x[i].a*x[i].b;
            n = n-x[i].a;
            sl++;
            kq[sl] = x[i];
        }
        else{
            res += n*x[i].b;
            sl++;
            kq[sl].a = n;
            kq[sl].b = x[i].b;
            break;
        }
    }
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ip();
    sort(x+1, x+1+m, cmp);
    slove();
    for(int i = 1; i <= sl; i++){
        cout<<kq[i].a<<" "<<kq[i].b<<'\n';
    }
    cout<<res;
}