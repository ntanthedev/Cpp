#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll T;
void solve(){
    int n, a[N], t = 1;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+1+n);
    while(t <= n){
        cout<<a[n]<<" ";
        if(t == n)
            break;
        cout<<a[t++]<<" ";
        n--;
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("daytrattu.inp","r",stdin);
    //freopen("daytrattu.out","w",stdout);
    cin >> T;
    while(T--)
        solve();
}
