#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll l = 0 , r = 0, n, a[N], s[N], smin[N];

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

void solve(){
    ll i = n, k = smin[n];
    if(k == 0)
        r = n;
    while(k >= 0){
        while(k < i && s[k] > s[i])
            i--;
        if(i - k > r - l){
            l = k;
            r = i;
        }
        if(k == 0)
            break;
        k = smin[k-1];
    }
    cout<<l+1<<" "<<r;
    // cout << r-l;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if(fopen("PS.inp","r")){
        freopen("PS.inp","r",stdin);
        freopen("PS.out","w",stdout);
    }
    int xx;
    read(n), read(xx); s[0] = 0; smin[0] = 0;
    for(int i = 1; i <= n; i++){
        read(a[i]);
        a[i] -= xx;
        s[i] = s[i-1] + a[i];
        if(s[i] < s[smin[i-1]]){
            smin[i] = i;
        }
        else{
            smin[i] = smin[i-1];
        }
    }

    solve();
}