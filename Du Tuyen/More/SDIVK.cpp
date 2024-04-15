// code by Đào Nhật Tân(ntannn)
#include <bits/stdc++.h>
#define tag "SDIVK"
#define ll long long
const int N = 1e6 + 9;
using namespace std;
int n, a[N], s[N], k, ans = 0;
int M[N];  // mảng dùng để đánh dấu
void solve() {
    M[0] = 1;
    /*việc đánh dấu M[0] = 1 có ý nghĩa nếu trong dãy
    tồn tại một vị trí mà s[i] = 0, hay tại đây thì tổng các số từ
    1 -> i sẽ chia hết cho k */
    for(int i = 1; i <= n; i++) {
        ans += M[s[i]];
        M[s[i]]++;
    }
    cout << ans;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag ".inp", "r")) {
        freopen(tag ".inp", "r", stdin);
        freopen(tag ".out", "w", stdout);
    }
    memset(M,
           0,
           sizeof(M));  // hàm dùng để đặt tất cả các giá trị trong mảng M về 0
    cin >> n >> k;
    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        s[i] = s[i] % k;  // với mỗi s[i], ta lấy dư của s[i] cho k;
    }
    solve();
}