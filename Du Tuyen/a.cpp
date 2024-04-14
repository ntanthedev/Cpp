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
    
    if(t == 1) {
        for(auto i : s) 
            if(i > s.front()) {
                string ans(s.size(), s.front());
                cout << ans;
                exit(0);
            }
        if(s.front() == '1') {
            string ans(s.size()-1, '9');
            cout << ans;
            exit(0);
        }
    }

    string a = s.substr(0, t);

    for(int i = 2; i <= t; i++) {
        a = a + s.substr(0, t);
    }
    
    if(a <= s) {
        cout << a;
        // exit(0);
    }
    else {
        string a = to_string(stoll(s.substr(0, t)) - 1);
        if(a.size() < s.size()) {

        }
        else {
            for(int i = 2; i <= t; i++) 
                cout << a;
        }
    }
}