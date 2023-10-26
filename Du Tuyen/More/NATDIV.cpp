#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll t[N], s[N], T, x, y;
void solve(){
    cin >> x >> y;
    cout<<s[y] - s[x-1]<<" "<<t[y] - t[x-1]<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("NATDIV.inp","r",stdin);
    freopen("NATDIV.out","w",stdout);
    memset(t, 0, sizeof(t));
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= 1000000; i++){
        for(int j = i; j <= 1000000; j += i){
            t[j] += i;
            s[j]++;
        }
    }
    for(int i = 1; i <= 1000000; i++){
        s[i] = s[i-1]+s[i];
        t[i] = t[i-1]+t[i];
    }
    cin >> T;
    while(T--)
        solve();
}
