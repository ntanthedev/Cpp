// created in 2024-08-27-20.33.23 in Code::Blocks 20.03
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, ans = 0;
int a[N];
pair<int, int> banle = {INT_MAX, INT_MAX};

int solve(int x, int y) {
    if(x > y)
        swap(x, y);
    if(2 * x <= y)
        return (y + 1) / 2;
    return (x + y + 2) / 3;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] < banle.first) {
            swap(banle.first, banle.second);
            banle.first = a[i];
        }
        else if(a[i] <= banle.second)
            banle.second = a[i];
    }

    ans = (banle.first + 1) / 2 + (banle.second + 1) / 2;

    a[0] = INT_MAX, a[n + 1] = INT_MAX;

    for(int i = 2; i < n; i++) {
        if(max(a[i - 1], a[i + 1]) < ans)
            ans = max(a[i - 1], a[i + 1]);
        int mmax = max(a[i - 1], a[i + 1]), mmin = min(a[i - 1], a[i + 1]);
        if(mmin + (mmax - mmin + 1) / 2 < ans)
            ans = mmin + (mmax - mmin + 1) / 2;
    }

    for(int i = 1; i < n; i++) {
        ans = min(ans, solve(a[i], a[i + 1]));
    }
    cout << ans;
}
