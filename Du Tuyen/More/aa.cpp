//problem "a"
//created in 10:42:24 - Wed 05/06/2024

#include<bits/stdc++.h>

#define int int64_t
#define fi first 
#define se second 

using namespace std;

int n;
vector<pair<int, int>> a;
vector<int> tree;

void update() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    a.resize(n + 1);
    vector<int> b(n + 1);
    unordered_map<int, int> m;
    tree.resize(4 * n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        b[i] = a[i].fi;
    }

    sort(b.begin() + 1, b.end());

    b[0] = 0;
    
    for(int i = 1; i <= n; i++) {
        int t = b[i];
        b[i] = (b[i] != b[i - 1] || i == 1 ? b[i - 1] + 1 : b[i - 1]);
        m[t] = b[i];
    }

    for(int i = 1; i <= n; i++) 
        a[i].fi = m[a[i].fi];


}