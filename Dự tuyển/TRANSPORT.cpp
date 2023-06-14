#include<bits/stdc++.h>
#define tag "TRANSPORT"
#define ll long long 
const int N = 1e6+9;
using namespace std;
ll a[N], n, s[N], W;
void solve(){
    for(int i = W; i >= 1; --i){
        if(s[i]){
            cout<<i;
            return;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> n >> W; W--;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    s[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = W; j >= a[i]; j--){
            if(s[j - a[i]] != 0)
                s[j] = 1;
        }
    }
    solve();
}