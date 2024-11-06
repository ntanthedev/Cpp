//created in 2024-08-27-10.35.59 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;

int f[N];

int cal(int s) {
    if(s == 0)
        return 0;

    if(f[s] != -1)
        return f[s];

    vector<int> digit;
    int t = s;
    while(t) {
        digit.push_back(t % 10);
        t /= 10;
    }

    f[s] = INT_MAX;
    for(auto j : digit) {
        if(j != 0)
            f[s] = min(f[s], cal(s - j) + 1);
    }
    return f[s];
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    memset(f, -1, sizeof f);
    cout << cal(n);
}

