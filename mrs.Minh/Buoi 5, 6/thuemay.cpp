#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n;
struct pt{
    ll d, c;
};
pt a[N];
bool cmp(pt x, pt y){
    return x.c < y.c;
}
void input(){
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i].d>>a[i].c;
}
void slove(){
    ll gmax = 0, x, y;
    sort(a+1, a+1+n, cmp);
    for(int i = 1; i < n; i++){
        if(a[i].c < a[i+1].d){
            if(a[i+1].d - a[i].c > gmax){
                x = a[i].c+1;
                y = a[i+1].d-1;
                gmax = y-x+1;
            }
        }
    }
    cout<<x<<" "<<y;
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("thuemay.inp","r",stdin);
    freopen("thuemay.out","w",stdout);
    input();
    slove();
}