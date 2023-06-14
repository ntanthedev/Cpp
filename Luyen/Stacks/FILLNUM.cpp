#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long N = 1e7+9;
ll n, k, mod, m;
vector<ll> s(N, -1);
struct pt{
    ll a, b, c, vt;
};
pt f[N];
bool cmp(pt x, pt y){
    return x.vt > y.vt;
}
void solve(){
    //fill(s.begin(), s.end(), -1);
    sort(f+1, f+1+m, cmp);
    for(int i = 1; i <= m; i++){
        if(f[i].a == -1)
            for(int j = f[i].a; j <= f[i].b; i++){
                if(s[j] != -1)
                    s[j] = f[i].c;
                else
                    break;
            }
        else 
            if(f[i].b == -1)
                for(int j = f[i].b; j >= f[i].a; j--){
                    if(s[j] != -1)
                        s[j] = f[i].c;
                    else
                        break;
                }
            else
                break;
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == -1)
            s[i] = 0;
        res = res*10 + s[i];
    }
    cout<<res%mod;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("FILLNUM.inp","r",stdin);
    freopen("FILLNUM.out","w",stdout);
    cin>>n>>m>>mod;
    for(int i = 1; i <= m; i++){
        cin>>f[i].a>>f[i].b>>f[i].c;
        f[i].vt = i;
    }
    solve();
}