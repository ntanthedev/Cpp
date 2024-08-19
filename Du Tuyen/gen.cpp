//problem "gen"
//created in 09:12:34 - Mon 19/08/2024

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937_64 rd(234);
const int end_test = 10;

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll> (l, r) (rd);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    srand(time(nullptr));
    system("g++ a.cpp -o a.exe");
    system("g++ b.cpp -o b.exe");

    for(int i = 1; i <= end_test; i++) {
        ofstream inp("test.inp");

        int test = Rand(1, 5);
        inp << test << '\n';
        while(test--)   {
            int a = Rand(1, 100);
            int b = Rand(a, 100);
            inp << a << " " << b << '\n';
        }
        inp.close();
        //sinh test here

        system("a.exe");
        system("b.exe");

        if(system("fc a.out b.out") != 0) {
            printf("test %d WA\n", i);
            return 0;
        }
        printf("test %d AC\n", i);
    }

}