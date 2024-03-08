//template simple for codeforces by ntannn_
//created in 12:23:52 - Thu 07/03/2024
#include <bits/stdc++.h>
#define int int64_t

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), s(n + 1);
    int f = 0; s[0] = 0;
    for(int i = 1; i <= n; i++) 
        cin >> a[i], f ^= a[i], s[i] = s[i-1] ^ a[i];
    if(!f) 
        return cout << "YES", void();
    for(int i = 1; i < n; i++) {
        for(int j = i; j < n; j++) {
            int x = s[0] ^ s[i], y = s[i] ^ s[j], z = s[j] ^ s[n];
            if(x == y && y == z)
                return cout << "YES", void();
        }
    }
    cout << "NO";
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}