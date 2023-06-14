#include<bits/stdc++.h>
#define ll long long
#define xau "BRIDGE"
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
const int N = 1e6+9;
using namespace std;
ll s[N], a[N], n, k, ans = 0;
unordered_map<ll, ll>M;
ll read()
{
    bool neg = 0;

    char c = getchar();
    for(; c < '0' || c > '9'; c = getchar())
        if(c == '-') neg = !neg;

    int n = 0;
    while('0' <= c && c <= '9')
        n = (n << 3) + (n << 1) + c - '0', c = getchar();

    return neg ? -n : n;
}
void solve(){
    for(int i = 1; i <= n; i++){
        if(M[s[i] - k] != 0)
            ans += M[s[i]-k];
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
    M[0] = 1;
    n = read();
    k = read();
    //cin >> n >> k;
    s[0] = 0;
    for(int i = 1; i <= n; i++){
        a[i] = read();
        s[i] = s[i-1] + a[i];
        M[s[i]]++;
    }
    solve();
}
