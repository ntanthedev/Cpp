//problem "a"
//created in 14:25:28 - Sat 07/12/2024

#include<bits/stdc++.h>

// #define int int64_t

using namespace std;

const int N = 1e6;

int n, test_case;
int a[N + 10], p[N + 10];



void solve() {
    int ans = INT_MAX;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        
    }    
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    memset(p, 0, sizeof(p));
    
    for(int i = 2; i <= sqrt(N); i++) 
        if(!p[i]) 
            for(int j = i * i; j <= N; j += i) 
                if(!p[j])
                    p[j] = i;
    
    for(int i = 0; i <= n; i++) 
        if(!p[i]) 
            p[i] = i;
    
    cin >> test_case;
    while(test_case--) {
        solve();
        cout << '\n';
    }
}