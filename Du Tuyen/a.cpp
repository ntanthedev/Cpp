//problem "a"
//created in 01:57:55 - Tue 30/07/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int n;

void cal(int i, string ans) {
    if(i > n) {
        cout << ans << '\n';
        return;
    }
    for(char j = '0'; j <= '1'; j++) {
        if(i == 1 || (ans.back() != '1' || j == '0')) {
            ans.push_back(j);
            cal(i + 1, ans);
            ans.pop_back();
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> n;

    string ans = "";
    cal(1, ans);
}