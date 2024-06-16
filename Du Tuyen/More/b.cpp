#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
void solve() {
    ll n;
    cin >> n;
    bool o = false;
    vector<ll> c(2 * n + 1);
    for(ll i = 1; i <= 2 * n; i++)
        cin >> c[i];
    for(ll i = 0; i <= n; i++) {
        deque<ll> a, b;
        for(ll j = 2 * n; j >= 2 * n - i + 1; j--)
            b.push_front(c[j]);
        ll flag = 2;
        for(ll j = 2 * n - i; j >= 1; j--) {
            if(j == (2 * n - i)) {
                a.push_front(c[j]);
                flag = 1;
            } else if(b.size() == n) {
                a.push_front(c[j]);
                flag = 1;
            } else if(a.size() == n) {
                b.push_front(c[j]);
                flag = 2;
            } else {
                if(c[j] > c[j + 1]) {
                    if(flag == 2)
                        b.push_front(c[j]);
                    else
                        a.push_front(c[j]);
                } else {
                    if(flag == 2) {
                        a.push_front(c[j]);
                        flag = 1;
                    } else {
                        b.push_front(c[j]);
                        flag = 2;
                    }
                }
            }
        }
        vector<ll> check(2 * n + 1);
        ll a1 = 0, b1 = 0, c1 = 1;
        while(a1 < n && b1 < n) {
            if(a[a1] < b[b1]) {
                check[c1] = a[a1], a1++, c1++;
            } else {
                check[c1] = b[b1], b1++, c1++;
            }
        }
        while(a1 < n) {
            check[c1] = a[a1], a1++, c1++;
        }
        while(b1 < n) {
            check[c1] = b[b1], b1++, c1++;
        }
        if(check == c) {
            for(auto i: a)
                cout << i << " ";
            cout << '\n';
            for(auto i: b)
                cout << i << " ";
            o = true;
            return;
        }
    }
    for(ll i = 0; i <= n; i++) {
        deque<ll> a, b;
        for(ll j = 2 * n; j >= 2 * n - i + 1; j--)
            a.push_front(c[j]);
        ll flag = 1;
        for(ll j = 2 * n - i; j >= 1; j--) {
            if(j == (2 * n - i)) {
                b.push_front(c[j]);
                flag = 2;
            } else if(b.size() == n) {
                a.push_front(c[j]);
                flag = 1;
            } else if(a.size() == n) {
                b.push_front(c[j]);
                flag = 2;
            } else {
                if(c[j] > c[j + 1]) {
                    if(flag == 2)
                        b.push_front(c[j]);
                    else
                        a.push_front(c[j]);
                } else {
                    if(flag == 2) {
                        a.push_front(c[j]);
                        flag = 1;
                    } else {
                        b.push_front(c[j]);
                        flag = 2;
                    }
                }
            }
        }
        vector<ll> check(2 * n + 1);
        ll a1 = 0, b1 = 0, c1 = 1;
        while(a1 < n && b1 < n) {
            if(a[a1] < b[b1]) {
                check[c1] = a[a1], a1++, c1++;
            } else {
                check[c1] = b[b1], b1++, c1++;
            }
        }
        while(a1 < n) {
            check[c1] = a[a1], a1++, c1++;
        }
        while(b1 < n) {
            check[c1] = b[b1], b1++, c1++;
        }
        if(check == c) {
            for(auto i: a)
                cout << i << " ";
            cout << '\n';
            for(auto i: b)
                cout << i << " ";
            o = true;
            return;
        }
    }
    if(!o)
        cout << -1 << '\n' << -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll tests = 1;
    while(tests--) {
        solve();
    }
}