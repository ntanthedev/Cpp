#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int S, ans = 0;
    cin >> S;
    for(int k = 0; k <= sqrt(S); k++) {
        int a = S/(k + 1) - k/2;
        int b = a + k;
        if((a + b) * (b - a + 1) / 2 == S)
            ans++;
    }
    cout << ans;
}
/*
s = a(k + 1) + k(k + 1) / 2
s/(k + 1) = a + k/2
s/(k + 1) - k/2 = a;
*/