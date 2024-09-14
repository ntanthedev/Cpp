#include <bits/stdc++.h>

using namespace std;
long long n, s = 0;
int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie(0); cout.tie(0);
    #define task "sums"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        s += 2 * i + 1;
    }
    cout << s;
    return 0;
}
