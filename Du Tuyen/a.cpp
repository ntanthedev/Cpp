//problem "a"
//created in 10:26:29 - Sun 15/09/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    vector<int> a(n + 2);

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    int res = 0, save = 0, ans = 0, X = a[1];    

    function<int(int, int)> cal = [&] (int x, int y) {
        if(X > x && (X <= y || y <= x)) 
            return (1 + cal(X, y));
        return (x >= y ? (m - x + y) : (y - x));
    };


    for(int i = 1; i < n; i++) {
        int c = cal(a[i], a[i + 1]);

        if(res + c > res + save + )
    }
}