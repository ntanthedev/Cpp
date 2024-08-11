#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, Q, a[200009];
map<ll, deque<ll>> D;
void khai() {
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        D[a[i]].push_back(i);
    }
    while(Q--) {
        int l, r, k;
        cin >> l >> r >> k;
        for(int x: D[k]) {
            // cout<<x<<" ";
        }
        ll Q = upper_bound(D[k].begin(), D[k].end(), r) - D[k].begin();
        ll E = lower_bound(D[k].begin(), D[k].end(), l) - D[k].begin();
        cout << Q - E << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(fopen("a.inp", "r")) {
        freopen("a.inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }
    khai();
}
