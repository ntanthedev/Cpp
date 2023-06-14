#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll a[N], cnt, k, ans = 9999999, n;
void solve(){
    for(int i = 1; i <= n; i++){
        cnt = 0;
        for(int j = 1; j <= n; j++){
            cnt += abs(a[i]+ ((j-i)*k) - a[j]);
        }
        ans = min(cnt, ans);
    }
    cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("BSEQ.inp","r",stdin);
    //freopen("BSEQ.out","w",stdout);
    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    solve();
}
