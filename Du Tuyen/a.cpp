//problem "a"
//created in 21:07:48 - Tue 22/10/2024

#include<bits/stdc++.h>

using namespace std;

string hieu(string a, string b) {
    string ans;
    
    while(b.size() < a.size()) 
        b = "0" + b;
    ans.resize(a.size());

    int n = a.size(), nho = 0;

    for(int i = n - 1; i >= 0; i--) { 
        int t;
        if(a[i] < b[i]) {
            t = (a[i] - '0' + 10) - (b[i] - '0' + nho);
            nho = 1;
        }
        else {
            t = (a[i] - '0') - (b[i] - '0' + nho);
            nho = 0;
        }
        ans[i] = (t + '0');
    }

    while(ans[0] == '0')
        ans.erase(ans.begin());

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string a, b;

    cin >> a >> b;

    cout << hieu(a, b);
}