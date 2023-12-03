#include <bits/stdc++.h>
using namespace std;
long long n, a[1000068], gmax = 0, s1 = 0, j = 0;
vector<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("DELNUM.inp","r",stdin);
    // freopen("DELNUM.out","w",stdout);
    cin >> n;
    for(long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    s.push_back(a[0]);
    s.push_back(a[1]);
    for(long long i = 2; i < n; i++) {
        while(s[s.size() - 1] < a[i] && s[s.size() - 2] > s[s.size() - 1] &&
              s.size() > 1) {
            s.pop_back();
            gmax++;
        }
        s.push_back(a[i]);
    }
    cout << n - gmax;
}
