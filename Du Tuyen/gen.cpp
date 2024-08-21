#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());
ll end_test = 100;

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll> (l, r) (rd);
}

signed main() {
    srand(time(NULL));

    system("g++ a.cpp -o a.exe");
    system("g++ b.cpp -o b.exe");


    for(int i = 1; i <= end_test; i++) {
        ofstream inp("test.inp");

        int n = Rand(1, 20);
        inp << n << '\n';
        for(int i = 1; i <= n; i++) {
            int a = Rand(1, 20);
            inp << a << " ";
        }

        inp.close();

        system("a.exe");
        system("b.exe");

        if(system("fc a.out b.out") != 0) {
            printf("test %d WA", i);
            return signed();
        }
        printf("test %d AC", i);
    }
}
