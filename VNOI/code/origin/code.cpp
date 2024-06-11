/*
   _____            _____  _    _  ______  _____    ____   __  __  _____   _ _
  / ____|    /\    / ____|| |  | ||  ____||  __ \  / __ \ |  \/  ||  __ \ | |  |
 |   /\
 | |        /  \  | |     | |__| || |__   | |__) || |  | || \  / || |  | || |  |
 |  /  \
 | |       / /\ \ | |     |  __  ||  __|  |  ___/ | |  | || |\/| || |  | || |  |
 | / /\ \
 | |____  / ____ \| |____ | |  | || |____ | |     | |__| || |  | || |__| || |__|
 |/ ____ \
  \_____|/_/    \_\\_____||_|  |_||______||_|      \____/ |_|  |_||_____/
 \____//_/    \_\

*/
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define llu unsigned long long
#define N 1123456
#define fi first
#define se second
#define VoTaGiaHuy int
using namespace std;
ll n, a[N];
string t;
char c;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #define task "GIAIMA"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> t >> c;
    string s = "";
    for(int i = 0; i < t.size(); i++)
        if(t[i] != c)
            s += t[i];
    int sz = s.size();
    if(sz % 2 != 0)
        return cout << -1, 0;
    for(int i = 0; i < sz / 2; i++)
        if(s[i] != s[i + sz / 2])
            return cout << -1, 0;
    for(int i = 0; i < t.size() - sz / 2; i++)
        cout << t[i];
}
