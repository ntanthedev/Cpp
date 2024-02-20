#include<bits/stdc++.h>

// #define int long long
const int MaxN = 1002;

using namespace std;

int n, m, c0, d0, a[12], b[12], c[12], d[12], e[12];
int f[12][MaxN][110];

int cal(int i, int w, int s) {
    if(f[i][w][s] != -1)
        return f[i][w][s];
    if(!i)
        return f[i][w][s] = (w/c0) * d0;
    
    f[i][w][s] = cal(i-1, w, e[i-1]);
    if(w >= c[i] && s > 0)
        f[i][w][s] = max(f[i][w][s], cal(i, w - c[i], s - 1) + d[i]);

    return f[i][w][s];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> c0 >> d0;
    for(int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        e[i] = a[i]/b[i];
    }
    a[0] = b[0] = 1;
    memset(f, -1, sizeof(f));
    cout << cal(m, n, e[m]);
}