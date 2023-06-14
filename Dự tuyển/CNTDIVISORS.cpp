#include<bits/stdc++.h>
#define ll long long
#define xau "CNTDIVISORS"
const int N = 1e6+9;
using namespace std;
ll a[N], n, s = 1, ans = 0;
void solve(){
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s *= a[i];
    }
    for(int i = 1; i <= sqrt(s); i++){
        if(s%i == 0){
            ans++;
            if(s/i != i)
                ans++;
        }
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
    cin >> n;
    solve();
}


