#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    #define task "test"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen("a.out", "w", stdout);
    }

    string s;
    cin >> s;

    int fixed_left = 0, fixed_right = 0, q = 0;
    for (char c : s) {
        if (c == '(') fixed_left++;
        else if (c == ')') fixed_right++;
        else q++;
    }

    int a = (fixed_right + q - fixed_left) / 2;
    int b = q - a;

    int n = s.size();
    vector<int> delta_suffix_close(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        char c = s[i];
        if (c == '(') {
            delta_suffix_close[i] = delta_suffix_close[i + 1] + 1;
        } else if (c == ')') {
            delta_suffix_close[i] = delta_suffix_close[i + 1] - 1;
        } else {
            delta_suffix_close[i] = delta_suffix_close[i + 1] - 1;
        }
    }

    int curr_balance = 0;
    int open_used = 0, close_used = 0;
    int max_depth = 0;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(') {
            curr_balance++;
            if (curr_balance > max_depth) {
                max_depth = curr_balance;
            }
        } else if (c == ')') {
            curr_balance--;
        } else {
            if (open_used < a) {
                int remaining_open = a - open_used - 1;
                int remaining_close = b - close_used;
                if (remaining_open >= 0 && remaining_close >= 0) {
                    int initial_delta = delta_suffix_close[i + 1];
                    int minimal_delta = initial_delta + 2 * remaining_open;
                    int current_balance_after = curr_balance + 1;
                    int total_min = current_balance_after + minimal_delta;
                    if (total_min >= 0) {
                        open_used++;
                        curr_balance++;
                        if (curr_balance > max_depth) {
                            max_depth = curr_balance;
                        }
                        continue;
                    }
                }
            }
            close_used++;
            curr_balance--;
        }
    }

    cout << max_depth << endl;
    return 0;
}