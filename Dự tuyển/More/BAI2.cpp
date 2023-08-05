#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

int n, k, a[N];
multiset<int> m;
multiset<int>::iterator it;

void solve() {
    sort(a+1, a+1+n);
    for(int i = n; i >= 1; i--) {
        it = m.upper_bound(a[i] - k);
        
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("BAI2.inp","r")){
        freopen("BAI2.inp","r",stdin);
        freopen("BAI2.out","w",stdout);
    }
    cin >> n >> k;
    fo(i, 1, n) {
        cin >> a[i];
        m.insert(a[i]);
    }
    solve();
}