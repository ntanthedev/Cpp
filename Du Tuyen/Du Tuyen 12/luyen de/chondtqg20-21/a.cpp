//created in 2024-08-26-08.34.00 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6;

int cnt_d[N + 10];
vector<ll> s;

void sub1(ll a, ll b) {
    int ans = 0;
    for(ll i = a; i <= b; i++)
        if(i % 3 == 0 && cnt_d[i] == 9) {
//            cout << i << '\n';
            ans++;
        }
    cout << ans << '\n';
}

void sub2(ll a, ll b) {
    a = sqrt(a);
    b = sqrt(b);
    cout << upper_bound(s.begin(), s.end(), b) - lower_bound(s.begin(), s.end(), a) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("NUM39.inp","r",stdin);
    freopen("a.out","w",stdout);

    memset(cnt_d, 0, sizeof(cnt_d));

    for(int i = 1; i <= N; ++i)
        for(int j = i; j <= N; j += i)
            cnt_d[j]++;

    for(int i = 2; i <= N; i++) {
        if(cnt_d[i] == 2 && i != 3) {
            if(i * 3 <= N)
                s.push_back(i * 3);
        }
    }

    int test;
    cin >> test;
    while(test--) {
        ll a, b;
        cin >> a >> b;
        if(b <= N)
            sub1(a, b);
        else
            sub1(a, b);
    }
}
