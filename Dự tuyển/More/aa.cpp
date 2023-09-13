#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse4,avx2,fma")
using namespace std;
typedef long long ll;
ll n, a[1000009],k,res;
deque<ll> d;

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

int main(){
      {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            // freopen("X.INP", "r", stdin);
            // freopen("X.OUT", "w", stdout);
      }
    read(n), read(k);
    for(int i = 1; i <= n; i++){
        read(a[i]);
    }
    for(int i = 1; i <= k; i++){
        d.push_front(a[1]);
    }
    for(int i = 2; i <= n; i++){
        res += d.back();
        d.pop_back();
        while(!d.empty() and d.front() > a[i]) d.pop_front();
        while(d.size() < k){
            d.push_front(a[i]);
        }
    }
    cout<<res + d.back();
}