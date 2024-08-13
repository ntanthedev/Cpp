//problem "BCIRCLE"
//created in 08:52:07 - Tue 13/08/2024

#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

#define x first 
#define y second 

using namespace std;

const int N = 1e5 + 5;
typedef long double ld;

int n;
pair<ld, ld> a[N];

ld cal(pair<ld, ld> x, pair<ld, ld> y) {
    ld c = (x.x - y.x) * (x.x - y.x);
    ld d = (x.y - y.y) * (x.y - y.y);

    return sqrt(c + d);  
}

void sub1() {
    ld ans = 3e6;

    for(int i = 1; i < n; i++) 
        for(int j = i + 1; j <= n; j++) {
            ans = min(ans, cal(a[i], a[j]));
        }
    
    cout << fixed << setprecision(2) << ans;
}

void sub2() {
    sort(a + 1, a + 1 + n);

    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "BCIRCLE"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> a[i].x >> a[i].y;

    // if(n <= 5000) 
        sub1();
    // else 
        // sub2();
}