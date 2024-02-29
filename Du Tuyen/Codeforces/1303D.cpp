#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int int64_t

using namespace std;

vector<int> bina(int x) {
    vector<int> y;
    int d = 0;
    while(x != 0) {
        if(x % 2 != 0)
            y.push_back(d);
        x /= 2;
        d++;
    }
    return y;
}

void solve() {
    int n, s;
    cin >> s >> n;
    vector<int> a(n), s2, s3;
    map<int, int> m;
    for(auto &i : a) {
        cin >> i;
    //    i = log2(i);
        m[log2(i)]++;
    }
    sort(all(a));
    s2 = bina(s);
    for(auto i : s2) {

    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    for(cin >> test_case; test_case--; cout << '\n') {
        solve();
    }
}
/*