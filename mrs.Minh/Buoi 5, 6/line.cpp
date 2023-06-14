#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, gmax = LLONG_MIN;

struct line
{
    /* data */
    ll d, c;
};
line a[N];
bool cmp(line x, line y){
    return((x.d < y. d) || ((x.d == y.d)&&(x.c < y.c)));
}
void slove(){
    sort(a+1, a+1+n, cmp);
    ll ld = a[1].d, lc = a[1].c;
    gmax = lc - ld;
    for(int i = 2; i <= n; i++){
        if(a[i].d > lc){
            ld = a[i].d;
            lc = a[i].c;
            gmax = max(gmax, lc - ld);
        }
        else{
            lc = max(lc, a[i].c);
            gmax = max(gmax, lc - ld);
        }
    }
    cout<<gmax;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("line.inp","r",stdin);
    freopen("line.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i].d>>a[i].c;
    }
    slove();
}