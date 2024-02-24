#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int long long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int temp;
    cin >> temp;
    vector<int> b;
    while(temp != 0) {
        b.push_back(temp % 2);
        temp /= 2;
    }
    reverse(all(b));
    for(auto i : b) 
        cout << i;
}