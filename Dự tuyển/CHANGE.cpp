#include<bits/stdc++.h>
#define tag "CHANGE"
using namespace std;

const int MAX_N = 100;
const int MAX_S = 10000;

int n, s;
int a[MAX_N + 1];
int f[MAX_N + 1][MAX_S + 1];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(tag".inp","r")){
        freopen(tag".inp","r",stdin);
        freopen(tag".out","w",stdout);
    }
    cin >> s >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int j = 0; j <= s; j++) {
        f[0][j] = numeric_limits<int>::max() / 2;
    }
    f[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j == 0) {
                f[i][j] = 0;
            } else if (a[i] > j) {
                f[i][j] = f[i-1][j];
            } else {
                f[i][j] = min(f[i-1][j], f[i][j-a[i]] + 1);
            }
        }
    }

    int i = n, j = s;
    vector<int> coins;
    while (i > 0 && j > 0) {
        if (f[i][j] == f[i-1][j]) {
            i--;
        } else {
            coins.push_back(a[i]);
            j -= a[i];
        }
    }

    cout << coins.size();
    cout << endl;

    return 0;
}
