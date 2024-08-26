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
            ans++;
    }
    cout << ans << '\n';
}

void sub2(ll a, ll b) {
//    a = sqrt(a);
//    b = sqrt(b);
//    for(auto it = lower_bound(s.begin(), s.end(), a); it != upper_bound(s.begin(), s.end(), b); it++)
//        cout << *it << '\n';
    cout << upper_bound(s.begin(), s.end(), b) - lower_bound(s.begin(), s.end(), a) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    freopen("NUM39.inp","r",stdin);
    freopen("NUM39.out","w",stdout);

    memset(cnt_d, 0, sizeof(cnt_d));

    for(int i = 1; i <= N; ++i)
        for(int j = i; j <= N; j += i)
            cnt_d[j]++;

//    for(int i = 1; i <= 500; i++) {
//        if(cnt_d[i] == 9 && i % 3 == 0)
//            cout << i << '\n';
//    }
//    exit(0);

    for(ll i = 2; i <= N; i++) {
        if(i == 27 || (cnt_d[i] == 2 && i != 3)) {
            if(i * 3 <= N)
                s.push_back(i * 3 * 3 * i);
        }
    }

    int test;
    cin >> test;
    while(test--) {
        ll a, b;
        cin >> a >> b;
        if(b <= N)
            sub2(a, b);
        else
            sub2(a, b);
    }
}
