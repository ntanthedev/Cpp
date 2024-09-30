//problem "b"
//created in 09:57:31 - Sun 29/09/2024

#include<bits/stdc++.h>
#define ll long long

const int N = 1e6 + 5;

using namespace std;

ll n, k, a[N];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "BALANSUB"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> n;

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    int ans = 0; 
    for(int i = 1; i <= n; i++) 
        for(int j = i; j <= n; j++) {
            if(a[j] < j - i + 1)
                break;
            ans = max(ans, j - i + 1);    
        }
    cout << ans;
}