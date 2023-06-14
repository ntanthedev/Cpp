#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, k, a[N], d[N], gmax = LLONG_MIN;
unordered_map<ll, ll>M, D;

void solve(){
    ll d = 0, v1 = 0, v2 = 0;
    D[0] = 1;
    for(int i = 1; i <= n; i++){
        if(a[i]%2 == 0)
            d++;
        else
            d--;
        if(D[d] == 0)
            D[d] = i;
        else{
            if(i - D[d] > gmax){
                gmax = i - D[d] - 1;
                v1 = D[d];
                v2 = i;
            }
        }
    }
    cout<<v1<<" "<<v2<<'\n';
    ll dem = 0;
    sort(a+1, a+1+n);
    a[0] = -99939;
    for(int i = 1; i <= n; i++){
        if(a[i] - a[i-1] > k)
            dem++;
    }
    cout<<dem;
}
/*
13 12 14 21 20 12
-1 0  1  0  1  2
*/
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("dayso42.inp","r",stdin);
    freopen("dayso42.out","w",stdout);
    cin>>n>>k;
    ll gmin = LLONG_MAX, gmax1 = LLONG_MIN, y1 = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        gmin = min(gmin, a[i]);
        gmax1 = max(gmax1, a[i]);
        if(M[a[i]] == 0)
            y1++;
        M[a[i]]++;
    }
    cout<<gmin<<" "<<gmax1<<'\n';
    cout<<y1<<'\n';
    solve();
}