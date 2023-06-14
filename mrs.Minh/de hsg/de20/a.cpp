#include <bits/stdc++.h>

using namespace std;

const int MAXK = 105;

int n, k, cnt[MAXK];

int main() {
    cin>>n>>k;
    for(int i = 0; i < n; ++i) {
        int x; cin>>x;
        ++cnt[x%k];
    }

    int ans = 0;
    if (cnt[0] > 0) ++ans;
    if (k%2 == 0 && cnt[k/2] > 0) ++ans;
    for(int r = 1; r <= (k-1)/2; ++r) {
        ans += max(cnt[r], cnt[k-r]);
    }

    cout<<ans;

    return 0;
}