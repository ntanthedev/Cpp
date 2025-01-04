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

        int n = Rand(1, 1e4), k = Rand(1, 1e3);
        vector<int> a;

        for(int i = 1; i <= n; i++) {
            a.push_back(Rand(1, 1e9));
        }

        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();

        inp << n << " " << k << '\n';

        for(auto i : a) 
            inp << i << " "; 
        inp << '\n';

        for(int i = 1; i <= k; i++) {
            inp << Rand(1, n) << " " << Rand(1, 1e9) << '\n';
        }
                
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