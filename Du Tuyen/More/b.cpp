//Written by: Jethro_
//----------------------
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 10;

string s;
int n, Hash[N], _pow[N], base = 311, ans = 0, l = 1e9, r;
vector<int> v;

long long get(int l, int r) {
    return Hash[r] - Hash[l - 1] * _pow[r - l + 1];
}
bool check(int mid) {
    for (int i = 2; i <= n - v[mid - 1]; ++i) {
        if (get(i, i + v[mid - 1] - 1) == get(1, v[mid - 1])) return true;
    }
    return false;
}
void solve() {
    cin >> s; n = s.size(); s = ' ' + s;
    _pow[0] = 1;
    Hash[0] = 0;

    for (int i = 1; i <= n; ++i) {
        _pow[i] = (_pow[i - 1] * base);
        Hash[i] = (Hash[i - 1] * base + s[i] - 'a' + 1);
    }
    for (int i = 1; i <= n - 1; ++i) {
        if (get(1, i) == get(n - i + 1, n)) {
            v.push_back(i);
        }
    }
    l = 1, r = v.size();
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;
    }
    if (ans == 0) {
        cout << "Just a legend";
        return;
    }
    for (int i = 1; i <= v[ans - 1]; ++i) cout << s[i];

}
int32_t main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    solve();

}
//1 2 3 4 5 6 7 8
//