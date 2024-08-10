//problem "a"
//created in 08:30:39 - Sat 10/08/2024

#include<bits/stdc++.h>

// #define int int64_t
// #define TIME (1.0 * clock() / CLOCKS_PER_SEC)
const int N = 1e6;

using namespace std;

vector<int> p(N + 10, 1), s(N + 10, 0);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "SPENUM"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    for(int i = 2; i <= (int)1e6; i++) {
        for(int j = i; j <= (int)1e6; j += i) {
            p[j]++;
        }
    }

    s[0] = 0;
    
    for(int i = 1; i <= (int)1e6 + 5; i++) {
        s[i] = s[i - 1] + (p[i] == 9);
    } 

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << s[b] - s[a - 1] << '\n';
    }
    
    // cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
