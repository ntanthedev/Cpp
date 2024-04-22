//problem "atcoder_dp_j"
//created in 06:44:11 - Tue 16/04/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int n, m[4];
long double f[301][301][301];

double cal(int x, int y, int z) {
    if(x < 0 || y < 0 || z < 0)
        return 0;
    if(x == 0 && y == 0 && z == 0) 
        return 0;
    if(f[x][y][z] > 0)
        return f[x][y][z];

    long double res = n + x * cal(x - 1, y, z) + y * cal(x + 1, y - 1, z) + z * cal(x, y + 1, z - 1);

    return f[x][y][z] = res / (x + y + z); 
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        m[x]++;
    }

    memset(f, -1, sizeof f);

    cout << fixed << setprecision(10) << cal(m[1], m[2], m[3]);  

}
