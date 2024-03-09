#include <bits/stdc++.h>
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll MOD = 1e9 + 7;
vector<ll> dp1(1000021), dp2(1000021);
ll x, y, d;
void extended_euclid(ll A, ll B) {
    if(B == 0) {
        x = 1;
        y = 0;
        d = A;
    } else {
        extended_euclid(B, A % B);
        ll temp = x;
        x = y;
        y = temp - (A / B) * y;
    }
}
long long modulo_inverse(long long a, long long M) {
    extended_euclid(a, M);
    return (x % M + M) % M;
}
ll c(ll x1, ll y1) {
    ll l = 1;
    l *= dp1[x1];
    l *= dp2[y1];
    l %= MOD;
    l *= dp2[x1 - y1];
    l %= MOD;
    return l;
}
ll A, B, k;
ll sqr(ll x2) {
    return x2 * x2;
}
const ll N = 1e6;
ll poww(ll a, ll b) {
    if(b == 0)
        return 1 % MOD;
    else {
        if(b % 2 == 0)
            return sqr(poww(a, b / 2)) % MOD;
        else
            return a * (sqr(poww(a, b / 2)) % MOD) % MOD;
    }
}
vector<ll> nt(1000021), ntt;
void sieve() {
    for(ll i = 1; i <= N; i++) {
        nt[i] = i;
    }
    for(ll i = 2; i <= N; i++) {
        if(nt[i] == i) {
            ntt.push_back(i);
            for(ll j = i * i; j <= N; j += i) {
                nt[j] = i;
            }
        }
    }
}
vector<ll> M(N + 21), save;
ll pt(ll xx) {
    ll yy = xx;
    ll d1 = 1;
    while(yy > 1) {
        bool o = false;
        if(yy > N) {
            for(auto i: ntt) {
                if(sqr(i) > yy)
                    break;
                else {
                    if(yy % i == 0) {
                        o = true;
                        if(!M[i])
                            save.push_back(i);
                        yy /= i;
                        M[i]++;
                        break;
                    }
                }
                if(o)
                    break;
            }
            if(!o) {
                M[yy]++;
                if(M[yy] == 1)
                    save.push_back(yy);
                break;
            }
        } else {
            ll xxx = nt[yy];
            if(!M[xxx])
                M[xxx]++;
            while(y % xxx == 0) {
                yy /= xxx;
                d1++;
            }
        }
    }
    for(auto i: save) {
        ll aaaaaaa = c(M[i] - 1, M[i] + k - 1);
        d1 *= aaaaaaa;
        d1 %= MOD;
    }
    return d1;
}

void solve() {
    ll ans = 0;
    ll sqq = (long long) (sqrt(B));
    for(ll i = 1; i <= sqq; i++) {
        if(B % i == 0) {
            ll hh = 0;
            ll ii = B / i;
            if(i <= A) {
                ll ddd = pt(i);
                ll dddd = pt(ii);
                ddd *= dddd;
                ddd %= MOD;
                hh = ddd;
                ans += hh;
                ans %= MOD;
            } else
                break;
            if(ii <= A) {
                if(i * i == B)
                    break;
                ans += hh;
                ans %= MOD;
            }
        }
    }
    cout << ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    dp1[0] = 1, dp2[0] = 1;
    for(ll i = 1; i <= N; i++) {
        dp1[i] = dp1[i - 1] * i;
        dp1[i] %= MOD;
    }
    for(ll i = 1; i <= N; i++) {
        dp2[i] = dp2[i - 1] * modulo_inverse(i, MOD);
        dp2[i] %= MOD;
    }
    cin >> A >> B >> k;
    solve();
}