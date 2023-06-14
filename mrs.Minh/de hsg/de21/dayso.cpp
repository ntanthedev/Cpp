#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, k, u, a[N], v, l , r;
void dao(ll x, ll y){
    while(x <= y){
        swap(a[x], a[y]);
        x++;
        y--;
    }
}
void taotest(){
    //cout<<"lan 0: ";
    for(int i = 1; i <= n; i++){
        a[i] = i;
        //cout<<a[i]<<" ";
    }
    //cout<<endl;
    for(int j = 1; j <= k; j++){
        dao(u, v);
        //cout<<"lan "<<j*2-1<<": ";
        //for(int i = 1; i <= n; i++)
            //cout<<a[i]<<" ";
        //cout<<endl;
        dao(l, r);
        // cout<<"lan "<<j*2<<": ";
        //for(int i = 1; i <= n; i++)
            //cout<<a[i]<<" ";
        // cout<<endl;
    }
    for(int i = 1; i <= n; i++)
        cout<<a[i]<<'\n';
}
void solve(){
    
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("dayso.inp","r",stdin);
    freopen("dayso.out","w",stdout);
    cin>>n>>k>>u>>v>>l>>r;
    // cout<<"u: "<<u<<"   v: "<<v<<'\n';
    // cout<<"l: "<<l<<"   r: "<<r<<'\n';
    k = k%36;
    taotest();
}
/*
          u       v
      l         r
    1 2 3 4 5 6 7 8 
l1: 1 2 3 8 7 6 5 4
l2: 1 2 4 5 6 7 8 3
l3: 1 2 4 3 8 7 6 5
l4: 1 2 5 6 7 8 3 4
l5: 1 2 5 4 3 8 7 6
l6: 1 2 6 7 8 3 4 5
*/