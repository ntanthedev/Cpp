#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5, D = 1e4 + 5, max_degree = 333;
int dp[D][D];
string solve() {
    int cnt1 = 0, cnt2 = 0;
    string a;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ')' || s[i] == '?')
            ++cnt1;
        else
            ++cnt2;
    }
    int avg = (cnt1 + cnt2) / 2;
    stack<char> st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') {
            st.push(s[i]);
            a += '(';
        } else if(s[i] == '?' && cnt2 < avg) {
            st.push('('), ++cnt2;
            a += '(';
        } else {
            if(s[i] == ')' || s[i] == '?') {
                st.pop();
                a += ')';
            }
        }
    }
    return a;
}
int result(string s) {
    int n = s.size(), res = 0;
    s = '0' + s;
    for(int i = 0; i <= max_degree; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(s[j] == '(')
                dp[j][i] = 1;
            else
                dp[j][i] = -1;
            cnt += dp[j][i];
            if(cnt == i)
                res = max(res, cnt);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BTN2.inp", "r", stdin);
    freopen("BTN2.out", "w", stdout);
    string ans = solve();
    cout << ans;
    return 0;
}
