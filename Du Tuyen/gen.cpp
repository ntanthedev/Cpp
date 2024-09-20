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

    for(int i = 1; i <= 10; i++) {
        ofstream inp("test.inp");

        int n = Rand(1, 10), q = Rand(1, 10);
        inp << n << " " << q << '\n';
        for(int i = 1; i <= n; i++) {
            int a = Rand(-10, 10);
            inp << a << " ";
        }
        for(int i = 1; i <= q; i++) {
            int c = Rand(1, 2), x, y;
            inp << c << " ";
            if(c & 1) {
                x = Rand(1, n), y = Rand(-10, 10);
                inp << x << " " << y << '\n';
            }
            else {
                x = Rand(1, n), y = Rand(x, n);
                inp << x << " " << y << '\n';
            }
        }

        inp.close();

        if(system("fc a.out b.out")) {
            printf("test %d WA\n", i);
            return signed();
        }

        printf("test %d AC\n", i);
    }
}