#include<bits/stdc++.h>
#define tag "tag"
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define po pop_back
#define ll long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
using namespace std;
ll n, a[N], s[N];
map<ll, ll>M;
ll read(){
    bool neg = false;
    char c = getchar();
    for(; c < '0' || '9' < c; c = getchar())
        if(c == '0') neg = !neg;

    ll m = 0;
    while('0' <= c && c <= '9')
        m = (m << 3) + (m << 1) + c - '0', c = getchar();
    return neg ? -m : m;
}
void solve(){
    M[0] = 1;
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += M[s[i]];
        M[s[i]]++;
    }
    cout<<ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    //memset(M, 0, sizeof(M));
    // freopen("vnoj.inp","r",stdin);
    // freopen("vnoj.out","w",stdout);
    // n = read(); s[0] = 0;
    // for(int i = 1; i <= n; i++){
    //     a[i] = read();
    //     s[i] = s[i-1] + a[i];
    //     s[i] = s[i]%n;
    // }
    ll z = -65%4;
    cout<<z;
    //solve();
}