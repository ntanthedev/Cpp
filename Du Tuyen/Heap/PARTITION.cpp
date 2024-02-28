#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 9;
ll L, n, a[N], sumarray = 0, ans = 0;

struct Less {
    bool operator()(ll x, ll y) { return x > y; }
};

priority_queue<ll, vector<ll>, Less> q;

void solve() {
    a[n + 1] = L - sumarray;
    if(a[n + 1] > 0)
        q.push(a[n + 1]);
    ll res;
    while(q.size() > 1) {
        res = 0;
        res += q.top();
        q.pop();
        res += q.top();
        q.pop();
        ans += res;
        q.push(res);
    }
    cout << ans;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("PARTITION.inp","r",stdin);
    // freopen("PARTITION.out","w",stdout);
    cin >> L >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sumarray += a[i];
        q.push(a[i]);
    }

    solve();
}