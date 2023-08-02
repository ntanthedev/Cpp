#include<bits/stdc++.h>
#define ll long long
#define xau "CNTPA"
const int N = 1e6+9;
using namespace std;
ll a[N], n, x;
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
    ll l = 1, r = n;
    if(a[l] > x/2){
        cout<<0;
        return;
    }
    while(l <= r){
        if(a[l] + a[r] > x)
            r--;
        else{

        }
    }
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
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        a[i] = read();
    solve();
}
