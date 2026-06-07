#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int nex[N];
void slove()
{
    int q;
    cin >> q;
    memset(nex, -1, sizeof(nex));
    for (int i = 1; i <= q; i++) {
        int f;
        cin >> f;
        if (f == 1) {
            int x;
            cin >> x;
            nex[i] = nex[x];
            nex[x] = i;
        } else {
            int x, y;
            cin >> x >> y;
            int tx = x;
            int ty = y;
            int cnt1 = 0;
            int cnt2 = 0;
            vector<int> st1, st2;
            while (1) {
                if (tx != -1)
                    tx = nex[tx];
                cnt1++;
                if (tx == y) {

                    nex[x] = y;
                    int sum = 0;
                    for (auto it : st1)
                        nex[it] = -1, sum += it;
                    cout << sum << "\n";
                    break;
                }
                st1.push_back(tx);
                if (ty != -1)
                    ty = nex[ty];
                cnt2++;
                if (ty == x) {
                    nex[y] = x;
                    int sum = 0;
                    for (auto it : st2)
                        nex[it] = -1, sum += it;
                    cout << sum << "\n";
                    break;
                }
                st2.push_back(ty);
            }
        }
        // int ff = 0;
        // while (ff != -1) {
        //     cout << ff << " ";
        //     ff = nex[ff];
        // }
        // cout << "\n";
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #define task "FIREWORK"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t = 1;
    while (t--)
        slove();
    return 0;
}