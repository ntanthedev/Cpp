// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

const int N = 3e3+9;

using namespace std;

int n, a[N][N];
bool b[N][N];

void solve() {
    memset(b, 0, sizeof(b));

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) 
            if(a[i][j]) {
                int r = a[i][j];
                for(int k = 0; k <= r; k++) 
                    b[min(n + 1, i + k)][min(n + 1, j + r - k + 1)] |= 1,
                    b[min(n + 1, i + k)][max(1, j - r + k)] |= 1,
                    b[max(1, i - k)][j + r - k + 1] |= 1,
                    b[(i - k)][i - r + k] |= 1;
            }
}


int main() {
	cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    
}
