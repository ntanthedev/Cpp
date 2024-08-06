#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
#define fi first 
#define se second
#define tag "GAS"
const int N = 1e6 + 9;
using namespace std;
typedef long long ll;

template<typename T> inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}

ll n, k, res = 0, a[N], sz;
deque<pair<ll, ll>> dq;

void solve() {
    dq.push_back({a[1], k});
    sz = k;
    for(int i = 2; i <= n; i++) {
        res += dq.front().first; //cout << dq.front().first << " ";
        dq.front().second--;
        sz--;
        if(!dq.front().second)
            dq.pop_front();
        while(!dq.empty() && dq.back().first > a[i]) {
            sz -= dq.back().second;
            dq.pop_back();
        }
        while(sz < k) {
            dq.push_back({a[i], k - sz});
            sz += k - sz;
        }
    }
    res += dq.front().first;  
    //cout<<dq.front().first<<" ";
    // dq.pop_front();
    cout << res;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag ".inp", "r")) {
        freopen(tag ".inp", "r", stdin);
        freopen(tag ".out", "w", stdout);
    }
    read(n), read(k);
    for(int i = 1; i <= n; i++)
        read(a[i]);
    solve();
}
