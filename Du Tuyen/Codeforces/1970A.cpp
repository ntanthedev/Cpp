//problem "1970A"
//created in 15:10:14 - Sat 04/05/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    vector<pair<int, int>> f; 
    map<int, int> m;

    cin >> s;
    
    for(int i = 0, d = 0; i < s.size(); i++) {
        f.emplace_back(d, i);
        d += (s[i] == '(') - (s[i] == ')');
        m[d]++;
    }


}