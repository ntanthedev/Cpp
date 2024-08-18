//problem "gen"
//created in 23:26:19 - Sat 17/08/2024

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
mt19937_64 rd(1);

ll Rand(ll l, ll r) {
    assert(l <= r);
    return uniform_int_distribution<ll> (l, r) (rd);
}

const int end_test = 5;

int32_t main() {

    srand(time(nullptr));
    system("g++ a.cpp -o a.exe");
    system("g++ b.cpp -o b.exe");
    
    for(int i = 1; i <= end_test; i++) { 
        ofstream inp("test.inp");
        
        int n = Rand(1, 10);
        inp << n << '\n';
        for(int i = 1; i <= n; i++) {
            int a = Rand(1, 10);
            inp << a << " ";
        }
        
        inp.close();

        system("a.exe");
        system("b.exe");

        if(system("fc a.out b.out") != 0) {
            printf("test %d wa\n", i);
            return 0;
        }
        
        printf("test %d ac\n", i);
    }
}