#include<iostream>
#include<cmath>
#include<string.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

using namespace std;

template <typename T> inline void read (T &x) {
    bool b = 0;
    char c;
    while (!isdigit (c = getchar()) && c != '-');
    if (c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while (isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if (b) {
        x=-x;
    }
}

bool is_prime[200001];
 int Max_Sang = 200000;
void sang_eratosthene(int x){
    is_prime[0] = 1;
    is_prime[1] = 1;
    for(int i = 2; i <= sqrt(x); i++)
        if(!is_prime[i])
            for(int j = i*i; j <= x; j += i)
                is_prime[j] = 1;
}
int a, b;

int32_t main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    read(a);
    read(b);
    sang_eratosthene(b);
    if(a <= 2)
        cout << 2 << '\n';
    if(a%2 == 0)
        a++;
    if(b%2 == 0)
        b--;
    for(; a <= b; a+=2)
        if(!is_prime[a])
            cout << a << '\n';
}