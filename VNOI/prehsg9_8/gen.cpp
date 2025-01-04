#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937_64 rd(time(nullptr));

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll> (l, r) (rd);
}

signed main() {

    system("g++ a.cpp -o a.exe");
    system("g++ b.cpp -o b.exe");

    for(int i = 1; i <= 100; i++) {
        ofstream inp("test.inp");

        int n = Rand(1e5, 5e6), k = Rand(1, 100);
        inp << n << ' ' << k << '\n';
                
        inp.close();

        system("a.exe");
        system("b.exe");

        if(system("fc a.out b.out")) {
            printf("test %d WA\n", i);
            return signed();
        }

        printf("test %d AC\n", i);
    }
}