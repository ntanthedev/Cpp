//template simple for codeforces by ntannn_
//created in 09:02:42 - Tue 23/07/2024
#include <bits/stdc++.h>

#define int int64_t
const int MOD = 1e9 + 7;

using namespace std;

/* Calculation with MODULO*/
int dec(int x, int y) {return (x-y+MOD)%MOD;}
int add(int x, int y) {return (x + y) % MOD;}
int mul(int x, int y) {return ((x%MOD) * (y%MOD)) % MOD;}
int bpow(int x, int y) {int res = 1; while (y) {if (y & 1) res = mul(res, x); x = mul(x, x); y >>= 1;} return res;}
int ModInverse(int x) {return bpow(x, MOD - 2);}
int Div(int x, int y) {return mul(x, ModInverse(y));}
int GetBit(int val, int num) {return ((val>>num) & 1LL);}


void solve() {
    int n;
    cin >> n;
    vector<int> divisions;
    map<int, int> f;

    for(int i = 2; i <= sqrt(n); ++i) 
        if(n % i == 0) {
            divisions.push_back(i);
            if(i != n / i) 
                divisions.push_back(n / i);
        }
    
    sort(divisions.begin(), divisions.end());

    function<int(int)> cal = [&](int s) {
        if(f[s] != 0)
            return f[s];
        
        int res = 0;
        for(auto i : divisions) {
            if(s % i == 0) 
                res = add(res, cal(s)); //tmp
        }
    };
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}