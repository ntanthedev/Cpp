//created in 2024-08-26-09.24.29 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937_64 rd(1);

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll> (l, r) (rd);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    srand(time(nullptr));
    #define file "NUM39"

    system("g++ a.cpp -o a.exe");
    system("g++ "file".cpp -o "file".exe");

    for(int i = 1; i <= 100; i++) {
        ofstream inp(file".inp");
        int t = Rand(1, 1000);
        inp << t << '\n';
        while(t--) {
            int a = Rand(1, 100), b = Rand(a, 1e6);
            inp << a << " " << b << '\n';
        }
        inp.close();

        system("a.exe");
        system(file".exe");

        if(system("fc a.out "file".out") != 0) {
            printf("test %d WA\n", i);
            return 0;
        }
        printf("test %d AC \n", i);
    }
}

