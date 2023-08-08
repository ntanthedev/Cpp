#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e6+9;
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

typedef long long ll;

int n, x;
int M[N];

void solve() {
    int ans = 0;
    fo(i, 1, N-1)
        if(M[i] > 1)
            ans = max(ans, i);
    cout << ans;
}

int main() 
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("a.inp","r")){
        freopen("a.inp","r",stdin);
        freopen("a.out","w",stdout);
    }
    read(n);
    fo(i, 1, n) {
        read(x);
        fo(j, 1, sqrt(x))
            if(x%j == 0) {
                M[j]++;
                if(x/j != j)
                    M[x/j]++;
            }
    }
    solve();
}