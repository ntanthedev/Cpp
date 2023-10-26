#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

int n, a[N];

void solve() {
    sort(a+1, a+1+n, greater<int>());
    ll s1 = 0, s2 = 0;
    s1 = a[1];
    s2 = a[2];
    fo(i, 3, n) {
        if(s1 < s2)
            s1 += a[i];
        else 
            s2 += a[i];
    }
    cout << min(s1, s2) << " " << max(s1, s2);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("BAI3.inp","r")){
        freopen("BAI3.inp","r",stdin);
        freopen("BAI3.out","w",stdout);
    }
    cin >> n;
    fo(i, 1, n)
        cin >> a[i];
    solve();
}