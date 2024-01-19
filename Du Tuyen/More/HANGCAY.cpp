#include <bits/stdc++.h>
 
#define task "hangcay"
 
typedef long long ll;
const int ar = 1e6+9;
 
using namespace std;
 
int n, m, x, r, res = 0;
bool vs[ar];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
 
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
 
 
    cin >> n >> m;
    while(m--) {
        cin >> x >> r;
        for(int j = x; j <= x + r; ++j) vs[j] = 1;
        for(int j = x; j >= max(1, x - r); --j) vs[j] = 1;
    }
 
    for(int i = 1; i <= n; ++i) res += vs[i];
    cout << res;
 
    return 0;
}