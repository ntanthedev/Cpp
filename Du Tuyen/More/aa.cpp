//template simple for codeforces by ntannn_
//created in 08:34:35 - Sat 24/02/2024
#include <bits/stdc++.h>
#define int long long
#define all(x) x.begin(),x.end()

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b;
    for(auto &i : a)
        cin >> i;
    sort(all(a));   
    int temp = n;
    while(temp != 0) {
        b.push_back(temp % 2);
        temp /= 2;
    }
    
        
}

signed main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int test_case;
    for(cin >> test_case;test_case--;cout << '\n') 
        solve();
}