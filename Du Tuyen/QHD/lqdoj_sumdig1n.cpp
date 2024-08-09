//problem "lqdoj_sumdig1n"
//created in 02:00:32 - Fri 09/08/2024

#include<bits/stdc++.h>

using namespace std;

template<typename T> inline void read(T& x) {
    bool b = 0;
    char c;
    while(!isdigit(c = getchar()) && c != '-')
        ;
    if(c == '-') {
        c = getchar();
        b = 1;
    }
    x = c - 48;
    while(isdigit(c = getchar())) {
        x = (x << 3) + (x << 1) + (c - 48);
    }
    if(b) {
        x = -x;
    }
}

long long f[18][2][140];

long long cal(int i, bool ok, long long res, vector<int> s) {
    if(i >= (int)s.size()) 
        return res;
    
    if(f[i][ok][res] != -1) 
        return f[i][ok][res];
    
    f[i][ok][res] = 0;

    for(int j = 0; j <= (ok ? 9 : s[i]); j++) {
        f[i][ok][res] += cal(i + 1, ok || (j < s[i]), res + j, s);
    }

    return f[i][ok][res];
}

long long solve(long long x) {
    if(x < 0) 
        return 0;    
    vector<int> s;
    
    while(x) {
        s.push_back(x % 10);
        x /= 10;
    }

    memset(f, -1, sizeof(f));
    reverse(s.begin(), s.end());

    return cal(0, 0, 0, s);
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    read(t);
    while(t--) {
        long long a, b;
        read(a), read(b);
        cout << solve(b) - solve(a - 1) << '\n';
    }
}