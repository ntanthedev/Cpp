#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> s(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] ^= s[i-1];
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << (s[x-1] ^ s[y]) << '\n';
    }
    //code by dnhat08
}