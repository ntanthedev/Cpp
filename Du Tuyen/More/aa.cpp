//problem "aa"
//created in 21:18:49 - Tue 30/04/2024

#include<bits/stdc++.h>

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define int int64_t

using namespace std;

vector<pair<pair<int, int>, int> > f;

bool check(int x) {
    int t = sqrt(x);
    return t * t == x;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for(int i = 1; i <= 1e4; i++) {
        for(int j = i; j <= 1e4; j++) {
            if(check(i*i + j*j))
                f.push_back({{i, j}, sqrt(i * i + j * j)});
        }
    }

    cout << f.size();

    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}