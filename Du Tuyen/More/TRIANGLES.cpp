#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
typedef long long ll;
ll n, m, h, a[N], i, u, j, c, t, b[N], k, q, Snha[N], kt[N];
ll S[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TRIANGLES.inp", "r", stdin);
    freopen("TRIANGLES.out", "w", stdout);
    cin >> n;
    t = 0;
    map<ll, ll> D;
    for(i = 1; i <= n; i++) {       
        cin >> a[i];
        D[a[i]]++;
        if(D[a[i]] == 1) {
            t++;
            b[t] = a[i];
        }
    }
    sort(b + 1, b + t + 1);
    k = 0;
    ll m = 0;
    for(ll i = 1; i <= t; i++) {
        if(D[b[i]] >= 3)
            k++;
        if(D[b[i]] >= 2) {
            m = lower_bound(b + 1, b + t + 1, 2 * b[i]) - b;
            k += m - i - 1;
            k = k + i - 1;
        }
    }
    h = 0;
    c = 0;
    for(ll i = 1; i <= t - 2; i++) {
        for(ll j = i + 1; j <= t - 1; j++) {
            h++;
            S[h] = b[i] + b[j];
            Snha[h] = j + 1;
            c++;
        }
    }
    for(h = 1; h <= c; h++) {
        for(i = Snha[h]; i <= t; i++) {
            if(S[h] > b[i])
                k++;
            else {
                break;
            }
        }
    }
    cout << k;
}