//problem "NUMBER"
//created in 07:39:24 - Tue 13/08/2024

#include<bits/stdc++.h>

using namespace std;

long long f[20][2][2][13][13];
vector<long long> s;

long long cal(long long i, bool ok, bool creat, long long pre, long long pree) {
    if(i == s.size()) {
        return 1;
    }
    if(f[i][ok][creat][pre][pree] != -1) { 
        return f[i][ok][creat][pre][pree];
    }

    f[i][ok][creat][pre][pree] = 0;

    for(long long j = 0; j <= (ok ? 9 : s[i]); j++) {
        if((j != pre && j != pree) || (j == 0 && !creat)) {
            if(!creat && j != 0)
                f[i][ok][creat][pre][pree] += cal(i + 1, ok | (j < s[i]), (j != 0 | creat), j, 11);
            else 
                f[i][ok][creat][pre][pree] += cal(i + 1, ok | (j < s[i]), (j != 0 | creat), j, pre);
        }
    }
    return f[i][ok][creat][pre][pree];
}

long long precal(long long x) {
    if(x < 10) 
        return x;

    s.clear();
    
    while(x) {
        s.push_back(x % 10);
        x /= 10;
    }

    reverse(s.begin(), s.end());
    memset(f, 255, sizeof(f));
    
    return cal(0, 0, 0, 0, 0) - 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    #define task "NUMBER"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    long long a, b;

    cin >> a >> b;
    cout << precal(b) - precal(a - 1);
}