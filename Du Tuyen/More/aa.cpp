#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("a.out","w",stdout);
    const int N = 1e5;
    int mmax = 0;
    map<int, int> m;
    vector<int> s(N + 1, 0);
    for(int i = 1; i <= sqrt(N); i++) {
        for(int j = 2; j * i <= N; j++) 
            s[i * j] += i;
    }
    for(int i = 1; i <= N; i++) {
        cout << i << ": " << s[i] << "\n" ;
        m[s[i]]++;
    }
    cout << m.size() << " " << (--m.end())->first << " " << (--m.end())->second;
}