#include <bits/stdc++.h>
#define diff(i, l, r) for(int i = l; i <= r; i++)
#define int long long
using namespace std;
const int N = 3e7 + 9;
int n, x;
bool f[N];
void sieve(){
    memset (f, true, sizeof(f));
    f[0] = f[1] = false;
    for (int i = 1; i <= sqrt(N); ++i){
        if(f[i])
            for (int j = i * i; j <= N; j += i)
                f[j] = false;
    }
}
void solve(){
    sieve();
    cin >> n;
    diff(i, 1, n) {
        cin >> x;
        while (!f[x]) ++x;
        cout << x << '\n';
    }
}
int32_t main(){
    ios::sync_with_stdio(false);  
    cin.tie(NULL);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    solve();
}