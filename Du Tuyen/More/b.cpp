#include <bits/stdc++.h>

// #define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    set<pair<int, int>> s;

    for (int i = 1; i <= 10; i++) {
        s.insert({rand() % 10, rand() % 10});
    }

    pair<int, int> x = {3, 7};
    auto r = s.upper_bound(x);
    cout << r->first << " " << r->second << '\n';
    while (r != s.end()) {
        if (x.second >= r->first) {
            // Lưu giá trị của r trước khi xóa
            auto temp = r;
            s.erase(r); 
            cout << temp->first << " " << temp->second << '\n';  // In giá trị đã lưu
            r = temp; // Tiếp tục duyệt từ vị trí đã xóa
        } else {
            break;
        }
        r++; // Di chuyển đến phần tử tiếp theo
    }
}
