// problem "a"
// created in 15:54:23 - Wed 24/07/2024

#include <bits/stdc++.h>

#define int int64_t
#define x first
#define y second

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        pair<int, int> a, b, c;

        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

        int ans = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);

        if(ans > 0)
            cout << "LEFT";
        else if(ans < 0)
            cout << "RIGHT";
        else
            cout << "TOUCH";
        cout << '\n';
    }
}