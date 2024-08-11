//problem "a"
//created in 00:17:00 - Mon 12/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    
    int n = 521378690;
    int cnt = 0;

    for(int i = 2; i <= n; i++) {
        if(n % i == 0) cnt++;
        while(n % i == 0) 
            n /= i;
        
    }

    cout << cnt;
}