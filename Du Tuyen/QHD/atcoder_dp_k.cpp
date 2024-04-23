//problem "atcoder_dp_k"
//created in 13:15:57 - Mon 22/04/2024

#include<bits/stdc++.h>

#define int int64_t
const int N = 1e5 + 2;

using namespace std;

int n, k;
int f[N][2], a[102];

bool cal(int s, bool r) {
    if(s < a[1])
        return r ^ 1;
    if(f[s][r] != -1)
        return f[s][r];

    f[s][r] = 0;
    for(int i = 1; i <= n && a[i] <= s; i++)
        f[s][r] |= cal(s - a[i], r ^ 1);
    
    return f[s][r];
}

int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    memset(f, -1, sizeof f);

    cout << (cal(k, 1) ? "First" : "Second");
}