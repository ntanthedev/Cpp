//problem "a"
//created in 10:09:52 - Sat 04/01/2025

#include<bits/stdc++.h>

const int N = 1e6 + 5;
typedef long long ll;

using namespace std;

ll n, q;
ll a[N];

struct sub1 {
    ll b[N + 9];

    sub1() {
        while(q--) {

        }
    }
};

struct sub2 {
    sub2() {

    }
};

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> q;

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    if(n * q <= 1e6) delete new sub1;
    else delete new sub2;
}