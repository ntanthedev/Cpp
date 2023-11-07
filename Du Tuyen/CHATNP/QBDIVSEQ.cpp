#include<bits/stdc++.h>

using namespace std;

signed main() {
    // freopen("QBDIVSEQ.inp","r",stdin);
    // freopen("QBDIVSEQ.out","w",stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    reverse(a.begin(), a.end());
    vector<int> b;
    b.push_back(a[0]);
    for(int i = 1; i < n; ++i) {
        if(a[i] < b[0])
            b[0] = a[i];
        else if(a[i] > b.back())
            b.push_back(a[i]);
        else 
            b[lower_bound(b.begin(), b.end(), a[i]) - b.begin()] = a[i];
    }
    cout << b.size();
}