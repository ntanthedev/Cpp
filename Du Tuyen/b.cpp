#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen("b.out", "w", stdout);
    }

    string s;
    cin >> s;
    int n = s.size();

    vector<int> L(n);
    int min_l = 0, max_l = 0;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == '(') {
            min_l++;
            max_l++;
        } else if (c == ')') {
            min_l--;
            max_l--;
        } else {
            min_l--;
            max_l++;
        }
        min_l = max(min_l, 0);
        L[i] = max_l;
    }

    vector<int> R(n);
    int min_r = 0, max_r = 0;
    for (int i = n-1; i >= 0; --i) {
        char c = s[i];
        if (c == ')') {
            min_r++;
            max_r++;
        } else if (c == '(') {
            min_r--;
            max_r--;
        } else {
            min_r--;
            max_r++;
        }
        min_r = max(min_r, 0);
        R[i] = max_r;
    }

    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        ans = max(ans, min(L[i], R[i+1]));
    }

    cout << ans << endl;
    return 0;
}
