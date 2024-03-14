#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int n, a[N], q, M[N];
set<int> s;
vector<int> res;

void ReadInput() {
    cin >> n;
    for (int i = 0; i <= n; ++i) cin >> a[i];
}
void solve() {
    for (int i = 0; i <= n; ++i) {
        M[a[i]] = i;
        if (a[i] != i && a[i] != 0) s.insert(a[i]);
    }
    while (s.size() >= 1) {
        int p = (M[0] == 0);
        if (M[0] != 0) {
            int tmp = M[0], temp2 = M[M[0]];
            s.erase(s.find(tmp));
            swap(M[0], M[M[0]]);
            res.push_back(a[temp2]);
            swap(a[tmp], a[temp2]);

        }else {
            auto t = s.begin();
            int tmp = M[0], temp2 = *t; 
            res.push_back(a[M[temp2]]);
            swap(a[tmp], a[M[temp2]]);
            M[0] = M[temp2];
            M[temp2] = tmp;

        }
    }
    cout << res.size() << '\n';
    // for (auto it : res) cout << it <<" ";


}
int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ReadInput();
    solve();

}
