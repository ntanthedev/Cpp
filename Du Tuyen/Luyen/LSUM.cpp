#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)
#define Fo(a, b, c) for(int a = b; a >= c; --a)

const long long N = 1e3+5;
using namespace std;

typedef long long ll;

int n, m, a[N][N];
ll ans = -1e9, doc[N][N], ngang[N][N], pre[N][N], smind[N][N], sminn[N][N];
bool checkduong = 0;
int gmax = -1e9;

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

inline void check() {
    cout << "------------\n";
    fo(i, 1, m) {
        fo(j, 1, n)
            cout << a[i][j] << " ";
        cout << '\n';
    }
    cout << "------------\n";
    fo(i, 1, m) {
        fo(j, 1, n)
            cout << doc[i][j] << " ";
        cout << '\n';
    }
    cout << "------------\n";
    fo(i, 1, m) {
        fo(j, 1, n)
            cout << ngang[i][j] << " ";
        cout << '\n';
    }
    cout << "------------\n";
    fo(i, 1, m) {
        fo(j, 1, n)
            cout << smind[i][j] << " ";
        cout << '\n';
    }
    cout << "------------\n";
    fo(i, 1, m) {
        fo(j, 1, n)
            cout << sminn[i][j] << " ";
        cout << '\n';
    }
}

inline void TH1() {
    fo(i, 1, m)
        fo(j, 1, n) {
            ngang[i][j] = ngang[i][j-1] + a[i][j];
            doc[i][j] = doc[i-1][j] + a[i][j];
            sminn[i][j] = min(sminn[i][j-1], ngang[i][j]);
            smind[i][j] = min(smind[i-1][j], doc[i][j]);
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i-1][j-1];
        }
    fo(i, 1, m) {
        fo(j, 1, n) {
            if(i == 1 && 1 == j)
                ans = max(ans, ll(a[i][j]));
            else {
                ans = max(ans, (doc[i][j] - smind[i][j]) + (ngang[i][j-1] - sminn[i][j-1]));
                ans = max(ans, (doc[i-1][j] - smind[i-1][j]) + (ngang[i][j] - sminn[i][j]));
                //cout << (doc[i][j] - smind[i][j]) + (ngang[i][j] - sminn[i][j]) << " ";
            }
        }
        //cout << '\n';
    }   
}

inline void TH2() {
    Fo(i, m, 1)
        Fo(j, n, 1) {
            ngang[i][j] = ngang[i][j+1] + a[i][j];
            doc[i][j] = doc[i+1][j] + a[i][j];
            sminn[i][j] = min(sminn[i][j+1], ngang[i][j]);
            smind[i][j] = min(smind[i+1][j], doc[i][j]);
        }
    
    Fo(i, m, 1) {
        Fo(j, n, 1) {
            if(i == m && n == j) {
                ans = max(ans, ll(a[i][j]));
                //cout << a[i][j] << " ";
            }
            else {
                ans = max(ans, (doc[i+1][j] - smind[i+1][j]) + (ngang[i][j] - sminn[i][j]));
                ans = max(ans, (doc[i][j] - smind[i][j]) + (ngang[i][j+1] - sminn[i][j+1]));
                //cout << (doc[i][j] - smind[i][j]) + (ngang[i][j] - sminn[i][j]) << " ";
            }
        }
        //cout << '\n';
    }
}

inline void TH3() {
    Fo(i, m, 1)
        fo(j, 1, n) {
            ngang[i][j] = ngang[i][j-1] + a[i][j];
            doc[i][j] = doc[i+1][j] + a[i][j];
            sminn[i][j] = min(sminn[i][j-1], ngang[i][j]);
            smind[i][j] = min(smind[i+1][j], doc[i][j]);
        }
    
    Fo(i, m, 1) {
        fo(j, 1, n) {
            if(i == m && 1 == j) {
                ans = max(ans, ll(a[i][j]));
                //cout << a[i][j] << " ";
            }
            else {
                ans = max(ans, (doc[i+1][j] - smind[i+1][j]) + (ngang[i][j] - sminn[i][j]));
                ans = max(ans, (doc[i][j] - smind[i][j]) + (ngang[i][j-1] - sminn[i][j-1]));
                //cout << (doc[i][j] - smind[i][j]) + (ngang[i][j] - sminn[i][j]) << " ";
            }
        }
        //cout << '\n';
    }
}

inline void TH4() {
    fo(i, 1, m)
        Fo(j, n, 1) {
            ngang[i][j] = ngang[i][j+1] + a[i][j];
            doc[i][j] = doc[i-1][j] + a[i][j];
            sminn[i][j] = min(sminn[i][j+1], ngang[i][j]);
            smind[i][j] = min(smind[i-1][j], doc[i][j]);
        }
    
    fo(i, 1, m) {
        Fo(j, n, 1) {
            if(i == 1 && n == j) {
                ans = max(ans, ll(a[i][j]));
                //cout << a[i][j] << " ";
            }
            else {
                ans = max(ans, (doc[i-1][j] - smind[i-1][j]) + (ngang[i][j] - sminn[i][j]));
                ans = max(ans, (doc[i][j] - smind[i][j]) + (ngang[i][j+1] - sminn[i][j+1]));
                //cout << (doc[i][j] - smind[i][j]) + (ngang[i][j] - sminn[i][j]) << " ";
            }
        }
        //cout << '\n';
    }
}

void solve() {
    TH1();
    TH2();
    TH3();
    TH4();
    if(!checkduong) 
        ans = gmax;
    cout << ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("LSUM.inp","r")) {
        freopen("LSUM.inp","r",stdin);
        freopen("LSUM.out","w",stdout);
    }
    read(m), read(n);
    fo(i, 1, n) {
        ngang[0][i] = 0;
        doc[0][i] = 0;
        pre[0][i] = 0;
        smind[0][i] = 0;
    }
    fo(i, 1, m) {
        ngang[i][0] = 0;
        doc[i][0] = 0;
        pre[i][0] = 0;
        sminn[i][0] = 0;
    }
    fo(i, 1, n) {
        ngang[m+1][i] = 0;
        doc[m+1][i] = 0;
        pre[m+1][i] = 0;
        smind[m+1][i] = 0;
    }
    fo(i, 1, m) {
        ngang[i][n+1] = 0;
        doc[i][n+1] = 0;
        pre[i][n+1] = 0;
        sminn[i][n+1] = 0;
    }
    fo(i, 1, m)
        fo(j, 1, n) {
            read(a[i][j]);
            gmax = max(gmax, a[i][j]);
            if(a[i][j] > 0) 
                checkduong = 1;
        }   
    solve();
}