#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll n, a[N], k, gmax = -999999999999, s[N], smin[N];
void solve(){
    for(int i = k; i <= n; i++){
        gmax = max(s[i] - smin[i-k], gmax);
    }
    cout<<gmax;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("SUBSEQ.inp","r",stdin);
    freopen("SUBSEQ.out","w",stdout);
    cin >> n >> k; s[0] = 0; smin[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s[i] = s[i-1] + a[i];
        //cout<<s[i]<<" ";
        smin[i] = min(smin[i-1], s[i]);
        //cout<<smin[i]<<" ";
    }
    solve();
}
/*
8 3
-20  90 -30 -20  80 -70 -60 125
-20  70  40  20 100  30 -30 95
*/
