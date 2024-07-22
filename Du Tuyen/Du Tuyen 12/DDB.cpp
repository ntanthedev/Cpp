#include<bits/stdc++.h>

#define int int64_t
const int N = 2e6 + 10;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "DDB"
    if(fopen(task".inp","r")) {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    vector<bool> b(2 * N, 1);
    b[0] = b[1] = 0;
    int cnt = 0;

    for(int i = 2, last = sqrt(2 * N); i <= last; ++i)
        if(b[i])
            for(int j = i*i; j <= 2 * N; j += i)
                b[j] = false;

    vector<int> p(2 * N);
    p[0] = 0;
    for(int i = 1; i <= 2 * N; ++i)
        p[i] = p[i - 1] + b[i];

    int t, x;
    cin >> t;
    while(t--) {
        cin >> x;
        cout << p[2 * x] - p[x] << '\n';
    }
}
