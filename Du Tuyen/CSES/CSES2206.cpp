//problem "CSES2206"
//created in 15:51:44 - Wed 26/02/2025

#include<bits/stdc++.h>

#define int int64_t
const int N = 2e5 + 5;

using namespace std;

int n, Q;
int a[N];
vector<vector<int>> s;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> Q;
    int sz = sqrt(n);
    int m = (n - 1) / sz + 1;
    s.resize(m + 1);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s[i / sz].push_back(a[i]);
    }

       
}