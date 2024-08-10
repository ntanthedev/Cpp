//problem "a"
//created in 08:30:39 - Sat 10/08/2024

#include<bits/stdc++.h>

// #define int int64_t
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
const int N = 1e6 + 9;

using namespace std;

int count_division (int x) {
    int t = sqrt(x), ans = 0;
    for(int i = 1; i <= t; i++) {
        if(x % i == 0) {
            ans++;
            if(x/i != i)
                ans++;
        }
    }
    return ans;
}

vector<int> p(N, 0), s(N, 0);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    // freopen()
    freopen("a.txt","w",stdout);

    // memset(p, 1, sizeof(p));

    for(int i = 2; i <= (int)1e6; i++) {
        for(int j = i; j <= (int)1e6; j += i) {
            p[j]++;
        }
    }
    for(int i = 1; i <= (int)1e6 + 5; i++) {
        s[i] = s[i - 1] + (p[i] == 9);
    } 

    cout << "{" ;
    for(int i = 0; i < s.size(); i++) {
        if(i > 0) 
            cout << ",";
        cout << s[i];
    } 
    
    cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
}
