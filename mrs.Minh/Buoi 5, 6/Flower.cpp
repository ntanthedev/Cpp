#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll gmax = 0, n, day = 0;
struct  pt
{
    /* data */
    ll vt, gt;
};
pt a[N];
bool cmp(pt x, pt y){
    return x.gt > y.gt;
}
void slove(){
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i <= n; i++){
        cout<<a[i].vt<<" ";
        day = max(a[i].gt+i, day);
    }
    cout<<'\n'<<day+1;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("flower.inp","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].gt;
        a[i].vt = i;
    }
    slove();
}