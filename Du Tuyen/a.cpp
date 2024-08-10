//problem "a"
//created in 21:50:53 - Fri 09/08/2024

#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

mt19937_64 rd(static_cast<unsigned int>(std::time(nullptr)));

ll Randd(ll l, ll r) {
    return uniform_int_distribution<ll>(l,r) (rd);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for(int i = 1; i <= 15; i++) {
        cout << Randd(-100, 100) << '\n';
    }
}