#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  int ans = 1;
  for (int i = 2; i * i <= x; ++i) {
    for (int j = i * i; j <= x; j *= i) {
      ans = max(ans, j);
    }
  }
  cout << ans << '\n';
  return 0;
}
