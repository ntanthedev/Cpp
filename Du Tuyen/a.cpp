//problem "a"
//created in 16:48:52 - Wed 14/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, max_bit = 0;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        max_bit = max(max_bit, __lg(a[i]));
    }

   for(int i = 1; i <= n; i++) cin >> a[i] }
