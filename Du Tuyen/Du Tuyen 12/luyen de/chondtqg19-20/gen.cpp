#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937_64 rd(1);

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll> (l, r) (rd);
}

signed main() {
    #define _ "NET"
    system("g++ a.cpp -o a.exe");
    system("g++ " _".cpp -o " _".exe");

    for(int i = 1; i <= 20; i++) {

        ofstream inp(_".inp");

        int n = Rand(1, 10), t = Rand(1, 20);
        inp << n << " " << t << '\n';
        for(int i = 1; i <= n; i++) {
            int a = Rand(1, 20), b = Rand(1, 20);
            inp << a << " " << b << '\n';
        }
        inp.close();

        system(_".exe");
        system("a.exe");

        if(system("fc a.out " _".out") != 0) {
            printf("test %d Wrong !!!\n", i);
            return 0;
        }

        printf("test %d Accepted  \n", i);
    }
}
