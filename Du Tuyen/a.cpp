//problem "a"
//created in 07:30:35 - Mon 19/08/2024

#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e4 + 5;

long long f[N][2][2][12][20];
int cnt[11];
string s;
string L, R;

string sub_num(string a, string b) {
    long long carry = 0, sum;
    string ans;
    for(int i = 0; i < max(a.size(), b.size()); i++) {
        if(a.size() == b.size()) break; 
        else if(a.size() < b.size()) {
            a = '0' + a;
        }
        else {
            b = '0' + b;
        }
    }
    ans = a;
    for(int i = a.size() - 1; i >= 0; i--) {
        sum = (a[i] - '0') - (b[i] - '0') - carry;
        if(sum < 0) {
            sum += 10;
            
            carry = 1;
        }
        else carry = 0;
        ans[i] = (sum + '0');
    }
    while(ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
    return ans;
}

int cal(int i, bool ok, bool creat, int pre, int r, bool num) {
    if(i == (num ? R.size() : L.size())) {
        return (r == 0);
    }

    if(f[i][ok][creat][pre][r] != -1)
        return f[i][ok][creat][pre][r];

    f[i][ok][creat][pre][r] = 0;

    for(int j = 0; j <= (ok ? 9 : (num ? (R[i] - '0') : L[i] - '0')); j++) {
        if(j == pre || (pre == 0 && creat))
            continue; 

        f[i][ok][creat][pre][r] += cal(i + 1, (ok | j < (num ? (R[i] - '0') : L[i] - '0')), (creat | j != 0), j, (r * 10 + j) % 19, num);
    }

    f[i][ok][creat][pre][r] %= MOD;

    return f[i][ok][creat][pre][r];
}

long long pre(int num) {
    if((num ? R.size() : L.size()) < 2) 
        return 0;
    
    memset(f, -1, sizeof(f));
    memset(cnt, 0, sizeof(cnt));
    
    return cal(0, 0, 0, 10, 0, num) - 1;
}

void solve() {
    cin >> L >> R;
    
    if(L != "1")
        L = sub_num(L, "1");

    // cout << pre(1) << " " << pre(0) << '\n';
    cout << (pre(1) - pre(0) + MOD) % MOD << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "num3"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    else {
        freopen("test.inp","r",stdin);
        freopen("a.out","w",stdout);
    }

    int test_case;
    cin >> test_case;
    while(test_case--) {
        solve();
    }
}
