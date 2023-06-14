#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll a[N], m, n, res = 0, kq[N];
struct  pt
{
    /* data */
    ll vt, gt;
};
pt b[N];
void input(){
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    for(int i = 1; i <= m; i++){
        cin>>b[i].gt;
        b[i].vt = i;
    }
}
bool sapgiam(ll x, ll y){
    return x > y;
}
bool saptang(pt x, pt y){
    return x.gt < y.gt;
}
void slove(){
    sort(a+1, a+1+n, sapgiam);
    sort(b+1, b+1+m, saptang);
    for(int i = 1; i <= n; i++){
        res += a[i]*b[i].gt;
        kq[i] = b[i].vt;
    }
    cout<<res<<'\n';
    sort(kq+1, kq+1+n);
    for(int i = 1; i <= n; i++)
        cout<<kq[i]<<'\n';
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("thamquan.inp","r",stdin);
    freopen("thamquan.out","w",stdout);
    input();
    slove();
}
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long 
// const long long R = 1e9+7;
// const long long N = 1e6+9;
// ll m, n, a[N];
// struct pt
// {
//     ll vt, gt;
// };
// pt b[N];
// bool cmp1(pt x, pt y){
//     return (x.gt < y.gt);
// }
// bool cmp2(pt x, pt y){
//     return (x.vt < y.vt);
// }
// void input(){
//     cin>>n>>m;
//     for(int i = 1; i <= n; i++)
//         cin>>a[i];
//     for(int i = 1; i <= m; i++){
//         cin>>b[i].gt;
//         b[i].vt = i;
//     }
// }
// void slove(){
//     ll res = 0;
//     sort(b+1, b+1+m,cmp1);
//     for(int i = 1; i <= n; i++){
//         res += b[i].gt*a[i];
//     }
//     cout<<res<<'\n';
//     sort(b+1, b+1+n, cmp2);
//     for(int i = 1; i <= n; i++){
//         cout<<b[i].vt<<'\n';
//     }
// }
// int main()
// {
//     cin.tie(NULL); cout.tie(NULL);
//     ios_base::sync_with_stdio(false);
//     freopen("thamquan.inp","r",stdin);
//     freopen("thamquan.out","w",stdout);
//     input();
//     slove();
// }