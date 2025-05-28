#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 10;

ll n, a[N], m = 0, s[N];
map<ll, ll> tmp;

vector<int> merge(vector<int> x, vector<int> y) {
    int i = 0, j = 0;
    vector<int> z;

    while(i < x.size() && j < y.size()) {
        if(x[i] < y[j]) 
            z.push_back(x[i++]);
        else 
            z.push_back(y[j++]);
    }

    while(i < x.size()) 
        z.push_back(x[i++]);
    while(j < y.size())
        z.push_back(y[j++]);

    return z;
}

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

    for(int i = 1; i <= n; i++) {
        s[a[i]]++;
    }
}