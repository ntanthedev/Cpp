#include<bits/stdc++.h>

#define int long long

using namespace std;
int n, m;
vector<int> a;

bool check(int mid) {
    int s = 0, k = 0;
    for(auto i : a) {
        if(i > mid)
            return 0;
        if(s + i > mid) {
            k++;
            s = 0;
        }
        s += i;
    }   
    k += (s > 0);
    return (k >= m);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define task "ELEVATOR2"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n);
    for(auto &i : a)
        cin >> i;
    int l = 1, r = 1e18, ans = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else 
            l = mid + 1;
    }
}