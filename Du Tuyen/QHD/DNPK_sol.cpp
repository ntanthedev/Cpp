#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int T = 1000000007;
const int MOD = 111539786;
const int N = 1005;

void read_file(){ 
    freopen("DNPK.INP", "r", stdin);
    freopen("DNPK.OUT", "w", stdout);
}

ll n, k, f[N][N];

ll Backtracking(int i, int d) {
    if(i == n) {
        if(d < k) return 1;
        return 0;
    }
    if(f[i][d] != -1) return f[i][d];
    f[i][d] = 0;
    if(d + 1 < k) f[i][d] += Backtracking(i + 1, d + 1); // 1
    f[i][d] += Backtracking(i + 1, 0); // 0
    return f[i][d] % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    read_file();
    while(cin >> n >> k) {
        memset(f, -1, sizeof(f));
        cout << Backtracking(0, 0) << endl;
    }
    return 0;
}