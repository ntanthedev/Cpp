//problem "a"
//created in 07:53:52 - Sat 14/09/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int w[30][3], n;
int s[3];
map<int, int> m;

inline void on_bit(int i, int &x) {
    x |= (1 << i);
} 

inline void off_bit(int i, int &x) {
    x &= ~(1 << i);
}

inline bool bit(int i, int x) {
    return (x >> i) & 1;
}

void ql1(int i, int mask) {
    if(i > n / 2) {
        int res = s[0] + s[1] + s[2];
        m[res] = mask;
        return;
    }

    for(int j = 0; j <= 1; j++) 
        for(int k = 0; k <= 1; k++) {
            if(j) on_bit(i << 1, mask);
            if(k) on_bit((i << 1) + 1, mask);
            ql1(i + 1, mask);
            if(j) off_bit(i << 1, mask);
            if(k) off_bit((i << 1) + 1, mask);
        }
}

void ql2(int i, int mask) {
    if(i > n) {
        int res = s[0] + s[1] + s[2];
        if(m.find(0 - res) != m.end()) {
            int maskk = m[0 - res];
            for(int j = 1; j <= (n >> 1); j++) {
                if(bit(j << 1, maskk))
                    cout << 'L';
                else 
                    cout << 'W';
                if(bit((j << 1) + 1, maskk))
                    cout << 'M';
                else 
                    cout << 'W';
                cout << '\n';
            }
            for(int j = (n >> 1) + 1; j <= n; j++) {
                if(bit(j << 1, mask))
                    cout << 'L';
                else 
                    cout << 'W';
                if(bit((j << 1) + 1, mask))
                    cout << 'M';
                else 
                    cout << 'W';
                cout << '\n';
            }
            exit(0); 
        }
        return;
    }

    for(int j = 0; j <= 1; j++) 
        for(int k = 0; k <= 1; k++) {
            if(j) on_bit(i << 1, mask);
            if(k) on_bit((i << 1) + 1, mask);
            ql2(i + 1, mask);
            if(j) off_bit(i << 1, mask);
            if(k) off_bit((i << 1) + 1, mask);
        }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;

    for(int i = 1; i <= n; i++) 
        for(int j = 0; j < 3; j++) 
            cin >> w[i][j];

    ql1(1, 0);

    ql2(n / 2 + 1, 0);

    cout << "Impossible";
}