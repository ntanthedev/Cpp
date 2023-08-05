#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

ll n;
vector<ll> vt;

void solve() {
    sort(vt.begin(), vt.end());
    int l = 0, r = n-1, ans = 0;
    while(l < r) {
        if(vt[l] + vt[r] > 4) {
            r--;
        }
        else {
            r--;
            l++;
        }
        ans++;
    }
    if(l == r)
        ans++;
    cout << ans;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("BAI1.inp","r")){
        freopen("BAI1.inp","r",stdin);
        freopen("BAI1.out","w",stdout);
    }
    cin >> n;
    vt.resize(n);
    for(int i = 0; i < n; i++)
        cin >> vt[i];
    solve();
}