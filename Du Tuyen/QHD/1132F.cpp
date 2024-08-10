//problem "1132F"
//created in 20:10:08 - Fri 09/08/2024

#include<bits/stdc++.h>

// #define int int64_t
const int N = 505;

using namespace std;

int n;
string s;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> s;

    s = ' ' + s;

    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 1; j--) {
            if(s[j] == s[i]) {
                
            }
        }
    }
}