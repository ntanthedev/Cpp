//template simple for codeforces by ntannn_
//created in 22:06:25 - Tue 13/02/2024
#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, res = 0, arv;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i, arv += i;
    arv /= n;
    cout << arv << " " ;
    for(auto &i : a) {
        if(i > arv)
            res += (i - arv);
        else {
            if(arv - i > res)
                return cout << arv << " " << i << " No", void();
            else 
                res -= (arv - i);
        }
    }
    cout << "Yes";
}

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}