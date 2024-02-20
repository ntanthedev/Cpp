#include<bits/stdc++.h>

#define int long long
const int MaxN = 1002;

using namespace std;

int n, m, c0, d0, a[MaxN], b[MaxN], c[MaxN], d[MaxN], e[MaxN];
int f[12][MaxN];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> c0 >> d0;
    for(int i = 1; i <= m; i++) 
        cin >> a[i] >> b[i] >> c[i] >> d[i], e[i] = a[i]/b[i];
    // memset(f, -1, sizeof f);
    // for(int i = 1; i <= m; i++)
    //     f[i][0] = 0;
    
    for(int i = 1; i <= m; i++) {
        for(int j = n; j >= c[i]; j--) {
            
        }
    }
}