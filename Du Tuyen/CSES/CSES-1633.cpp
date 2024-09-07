//created in 2024-08-27-08.48.40 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;
const int MOD = 1e9 + 7;

int n;
int64_t f[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        if(i <= 6)
            f[i] = 1;
        for(int j = 1; j <= 6; j++)
            if(i - j > 0)
                f[i] += f[i - j];
        f[i] %= MOD;
    }

    cout << f[n];
}
