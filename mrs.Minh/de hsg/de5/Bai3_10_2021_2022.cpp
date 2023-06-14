#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, res = 0;
struct pt{
    ll d, c;
};
pt a[N], b[N];
bool cmp(pt x, pt y){
    return(x.c < y.c);
}
void input(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].d>>a[i].c;
    }
}
void slove(){
    for(int i = 1; i < n; i++){
        if(a[i].c < a[i+1].d){
            res++;
            b[res].d = a[i].d;
            b[res].c = a[i].c;
            res++;            
            b[res].d = a[i+1].d;
            b[res].c = a[i+1].c;
            i++;
        }
    }
}
void output(){
    for(int i = 1; i <= res; i++){
        cout<<b[i].d<<" "<<b[i].c<<'\n';
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("Bai3_10_2021_2022.inp","r",stdin);
    freopen("Bai3_10_2021_2022.out","w",stdout);
    input();
    sort(a+1,a+1+n,cmp);
    slove();
    output();
}