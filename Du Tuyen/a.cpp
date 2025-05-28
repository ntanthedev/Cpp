#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

ll n, a[N], m = 0;
map<ll, ll> tmp;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp[a[i]]++;
    }

    for(auto &i : tmp) {
        i.second = ++m;
    }

    for(int i = 1; i <= n; i++) 
        a[i] = tmp[a[i]];

    
}