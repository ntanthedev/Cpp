#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("code.inp","r",stdin);
    freopen("code.out","w",stdout);
    long long t, n, m;
    cin >> n >> m;
    t = n/2;
    while(t%m != 0)
        t++;
    cout << t;
    return 0;
}
