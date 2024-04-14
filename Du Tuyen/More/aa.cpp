//problem "a"
//created in 18:41:57 - Sat 13/04/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    cin >> s;
    int t = s.size();
    for(int i = 2; i <= t; i++) 
        if(t % i == 0) {
            t /= i; break;
        }

    string a = to_string(stoi(s.substr(0, t)) - 1);

    if(a.size() < t)

    for(int i = 1; i <= t; i++) {
        cout << a; 
    }
}