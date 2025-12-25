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
        ofstream inp_a("a.inp");
        ofstream inp_b("b.inp");

        int n = Rand(1, 15);
        inp_a << n << '\n';
        inp_b << n << '\n';
        
        for(int i = 1; i <= n; i++) {
            ll val = Rand(-1e2, 1e2);
            inp_a << val << " ";
            inp_b << val << " ";
        }

        inp_a.close();
        inp_b.close();

        system("a.exe");
        system("b.exe");

        if(system("fc a.out b.out") != 0) {
            printf("test %d WA\n", i);
            return signed();
        }

        printf("test %d AC\n", i);
    }
}