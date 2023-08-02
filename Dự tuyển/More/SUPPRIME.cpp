#include<bits/stdc++.h>
#define ll long long
#define xau "SUPPRIME"
const int N = 1e6+9;
using namespace std;
ll k;
pair<ll, ll>a[N];
bool b[10000000];
void sang(){
    memset(b, true, sizeof(b));
    b[0] = false;
    b[1] = false;
    for(int i = 2; i <= sqrt(10000000); i++)
        if(b[i])
            for(int j = i*i; j <= 10000000; j += i)
                b[j] = false;
}
void solve(){
    sang();
    ll i = 2, d1 = 0, d2 = 0, ans;
    while(d2 <= k){
        if(b[i]){
            d1++;
            if(b[d1]){
                d2++;
                if(d2 == k){
                    ans = i;
                }
            }
        }
        i++;
    }
    cout<<ans;
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
    cin >> k;
    solve();
}
