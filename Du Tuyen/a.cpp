//problem "a"
//created in 09:54:07 - Sat 10/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

    mt19937_64 rd (time(nullptr));
int Rand(int l, int r) {
    return l + 
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("a.txt","w",stdout);


    for(int i = 1; i <= 100; i++) {
        cout << 
    }
}
// //problem "a"
// //created in 08:30:39 - Sat 10/08/2024

// #include<bits/stdc++.h>

// // #define int int64_t
// #define TIME (1.0 * clock() / CLOCKS_PER_SEC)
// const int N = 1e6 + 9;

// using namespace std;

// vector<int> p(N, 1), min_prime(N, 0);

// int main() {
//     ios_base::sync_with_stdio(false); cin.tie(NULL);
    
//     // freopen()
//     freopen("a.txt","w",stdout);

//     // memset(p, 1, sizeof(p));

//     for(int i = 2; i <= (int)1e6; i++) {
//         for(int j = i; j <= (int)1e6; j += i) {
//             p[j]++;
//             if(!min_prime[j] && p[i] == 2)
//                 min_prime[j] = i;
//         }
//     }

//     for(int i = 1; i <= N; i++) 
//         if(!min_prime[i])
//             min_prime[i] = i;

//     for(int i = 1; i <= N; i++) {
//         if(p[i] == 9) {
//             cout << i << ": ";
//             int t = i;
//             set<int> s;
//             while(t != 1) {
//                 s.insert(min_prime[t]);
//                 t /= min_prime[t];
//             }
//             for(auto j : s) 
//                 cout << j << " ";
//             cout << '\n';
//         }
//     }

    
//     cerr << '\n' << "\x1b[31mtime is: " << TIME << "\e[39m";
// }