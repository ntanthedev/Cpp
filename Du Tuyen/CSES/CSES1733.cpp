//problem "CSES2422"
//created in 15:55:38 - Wed 07/08/2024

#include<bits/stdc++.h>

#define int long long 
const int N = 1e6 + 10;
const int base = 311;
const int MOD = 1e9 + 7;

using namespace std;

int H[N], n, POW[N];
string s;

int get_hash(int i, int j) {
    return (H[j] - H[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}

bool check(int k) {
    int hash = get_hash(1, k);
    int i = 1;
    for(;i + k - 1 <= n; i += k) {
        if(get_hash(i, i + k - 1) != hash)
            return 0;        
    }
    if(i == 1 || k == n)
        return true;
    int j = n - i + 1;
    return get_hash(1, j) == get_hash(i, n);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> s;

    n = s.size();
    s = ' ' + s;
    
    POW[0] = 1;
    for(int i = 1; i <= n; i++) {
        POW[i] = (POW[i - 1] * base) % MOD;
    }

    for(int i = 1; i <= n; i++) {
        H[i] = (H[i - 1] * base + s[i] - 'a' + 1) % MOD;
    }

    for(int k = 1; k <= n; k++) {
        if(check(k))
            cout << k << " ";
    }

}

