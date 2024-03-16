#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1001][1001][2];
string s;
const ll mod = 111539786;

ll n, k, next1[1001], next2[1001];

ll solve(ll j, ll deg, bool ok) {
    ll k1;
    if(f[j][deg][ok] != -1)
        return f[j][deg][ok];
    k1 = (deg == 0 && ok);
    if(deg < k && next1[j] < n + 1)
        k1 += solve(next1[j], deg + 1, (deg + 1 == k || ok)) % mod;
    if(deg > 0 && next2[j] < n + 1)
        k1 += solve(next2[j], deg - 1, ok) % mod;
    return f[j][deg][ok] = k1;
}
//()()
//
void khoitao() {
    ll x = n + 1;
    ll y = n + 1;
    for(ll i = n - 1; i >= -1; i--) {
        next1[i + 1] = x;
        next2[i + 1] = y;   
        if(i > -1 && s[i] == '(')
            x = i + 1;
        else if(i > -1)
            y = i + 1;
    }
    
}

int main() {
    // freopen("BTNK.inp", "r", stdin);
    // freopen("BTNK.out", "w", stdout);
    cin >> s;
    scanf("%ld", &k);
    memset(f, 255, sizeof(f));
    n = s.length();
    khoitao();
    for(int i = 0; i <= n; i++) cout << next1[i] << " "; cout << '\n';
    for(int i = 0; i <= n; i++) cout << next2[i] << " "; cout << '\n'; 
    // cout << solve(0, 0, false) % mod;
}


// next1 la con ) ben phai dau tien
// next2 la con ( ben phai dau tien 



// ()() ()() ()


// 1 -> 2 -> 3 -> 4
// 1 -> 3

// )())()  () ()()
