#include <bits/stdc++.h>
using namespace std;

#define MAXN 55
#define MOD 1000000007
#define int long long

int DP[MAXN], n, k;

int compute (int left) {
    if (DP[left] != 0) {
        return DP[left];
    }
    for (int i = 1; i <= k; i++) {
        if (left - i >= 0) {
            DP[left] += compute(left - i);
            // DP[left] %= MOD;
        }
    }
    return DP[left];
}

signed main() {
    #define task "PICTURE"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n >> k;
    memset(DP, 0, sizeof(DP));
    DP[0] = 1;
    cout << compute(n) << endl;
}
