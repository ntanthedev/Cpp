#include<bits/stdc++.h>

#define int long long
const int N = 505;

using namespace std;

int n, m, k;
int D[N][N], d[N][N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define _ "SERVICE"
    freopen(_".inp","r",stdin);
    freopen(_".out","w",stdout);

    cin >> n >> m >> k;

    for(int i = 1; i <= 500; ++i)
        for(int j = 1; j <= 500; ++j)
            d[i][j] = (i != j ? 1e16 : 0);

    for(int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        d[u][v] = w;
    }

    for(int t = 1; t <= k; ++t) {

        for(int i = 1; i <= n + 3; ++i)
            for(int j = 1; j <= n + 3; j++)
                D[i][j] = d[i][j];

        int p;
        cin >> p;
        for(int i = 1, u, v, w; i <= p; ++i) {
            cin >> u >> v >> w;
            D[u][v] = w;
        }

        for(int w = n + 1; w <= n + 3; ++w) {
            for(int u = 1; u <= n + 3; ++u)
                for(int v = 1; v <= n + 3; ++v)
                    if(D[u][v] > D[u][w] + D[w][v])
                        D[u][v] = D[u][w] + D[w][v];
        }

        //for(int u = 1; u <= n + 3; ++u)
            //for(int v = 1; v <= n + 3; ++v)
                //cout << u << " -> " << v << ": " << D[u][v] << '\n';

        int ans = 0;
        for(int i = 1; i <= n + 3; ++i)
            for(int j = 1; j <= n + 3; ++j)
                ans += D[i][j];

        cout << ans << '\n';
    }

}