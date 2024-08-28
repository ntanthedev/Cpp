// created in 2024-08-28-16.33.48 in Code::Blocks 20.03
#include <bits/stdc++.h>

#define int int64_t

using namespace std;

int D, K;
int f[17][2][2][11][17];
vector<int> s;

int cal(int i, bool ok, bool creat, int pre, int cnt) {
    if(i == (int) s.size())
        return 1;

    if(f[i][ok][creat][pre][cnt] != -1)
        return f[i][ok][creat][pre][cnt];

    f[i][ok][creat][pre][cnt] = 0;

    for(int j = 0; j <= (ok ? 9 : s[i]); j++) {
        if(creat && abs(j - pre) <= D && cnt == K)
            continue;
        f[i][ok][creat][pre][cnt] += cal(i + 1, (ok || j < s[i]), creat || (j != 0), j, cnt + (abs(j - pre) <= D && creat));
    }

//     cout << i << " " << ok << " " << creat << " " << pre << " " << cnt << '\n';
//     cout << f[i][ok][creat][pre][cnt] << '\n';

    return f[i][ok][creat][pre][cnt];
}

int pre(int x) {
    if(x < 10)
        return x;

    memset(f, -1, sizeof f);
    s.clear();

    while(x) {
        s.push_back(x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());

    return cal(0, 0, 0, 10, 0) - 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b >> D >> K;

    cout << pre(b) - pre(a - 1);
}
