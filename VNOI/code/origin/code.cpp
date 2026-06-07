#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;

struct Element {
    ll value;
    int id;
};

const int N = 8000005;
int dp_trace[N];

void sub12(int n, ll l, ll r, const vector<ll>& w) {
    int n_l = n / 2;
    int n_r = n - n_l;

    vector<pair<ll, int>> l_sums;

    l_sums.reserve(1 << n_l);

    for(int i = 0; i < (1 << n_l); ++i) {
        ll crs = 0;
        for(int j = 0; j < n_l; ++j) {
            if((i >> j) & 1)
                crs += w[j];
        }
        l_sums.pb({crs, i});
    }

    sort(l_sums.begin(), l_sums.end());

    for(int i = 0; i < (1 << n_r); ++i) {
        ll cr = 0;
        for(int j = 0; j < n_r; ++j) {
            if((i >> j) & 1)
                cr += w[n_l + j];
        }

        ll tmin = l - cr;
        ll tmax = r - cr;

        auto it =
            lower_bound(l_sums.begin(), l_sums.end(), make_pair(tmin, -1));

        if(it != l_sums.end() && it->first <= tmax) {
            int mask_l = it->second;
            int mask_r = i;

            vector<int> res;

            for(int j = 0; j < n_l; ++j) {
                if((mask_l >> j) & 1)
                    res.pb(j + 1);
            }

            for(int j = 0; j < n_r; ++j) {
                if((mask_r >> j) & 1)
                    res.pb(n_l + j + 1);
            }

            sort(res.begin(), res.end());
            cout << res.size() << "\n";
            for(int k = 0; k < res.size(); ++k) {
                cout << res[k] << (k == res.size() - 1 ? "" : " ");
            }
            cout << "\n";
            return;
        }
    }
}

void sub3(int n, ll l, ll r, const vector<ll>& w) {
    ll total_sum = 0;
    for(ll x: w)
        total_sum += x;

    fill(dp_trace, dp_trace + total_sum + 1, -1);
    dp_trace[0] = -2;

    ll cms = 0;

    for(int i = 0; i < n; ++i) {
        ll val = w[i];

        for(ll s = cms; s >= 0; --s) {
            if(dp_trace[s] != -1) {
                ll next_s = s + val;
                if(dp_trace[next_s] == -1) {
                    dp_trace[next_s] = i;

                    if(next_s >= l && next_s <= r) {
                        vector<int> res;
                        ll temp = next_s;
                        while(temp > 0) {
                            int idx = dp_trace[temp];
                            res.pb(idx + 1);
                            temp -= w[idx];
                        }
                        sort(res.begin(), res.end());
                        cout << res.size() << "\n";
                        for(int k = 0; k < res.size(); ++k) {
                            cout << res[k] << (k == res.size() - 1 ? "" : " ");
                        }
                        cout << "\n";
                        return;
                    }
                }
            }
        }
        cms += val;
    }
}

void sub45(int n, ll limit_l, ll limit_r, const vector<ll>& w) {
    vector<Element> arr(n);
    for(int i = 0; i < n; ++i) {
        arr[i] = {w[i], i + 1};
    }

    sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
        return a.value < b.value;
    });

    int l = 0;
    int r = 0;
    ll crs = 0;

    while(r < n) {
        crs += arr[r].value;
        r++;

        while(crs > limit_r && l < r) {
            crs -= arr[l].value;
            l++;
        }

        if(crs >= limit_l && crs <= limit_r) {
            vector<int> res;
            for(int k = l; k < r; ++k) {
                res.pb(arr[k].id);
            }
            sort(res.begin(), res.end());
            cout << res.size() << "\n";
            for(int k = 0; k < res.size(); ++k) {
                cout << res[k] << (k == res.size() - 1 ? "" : " ");
            }
            cout << "\n";
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define task "code"
    if(fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll l, r;
    cin >> n >> l >> r;

    vector<ll> w(n);
    ll sum_all = 0;
    for(int i = 0; i < n; ++i) {
        cin >> w[i];
        sum_all += w[i];
    }

    if(n <= 40) {
        sub12(n, l, r, w);
    }

    else if(sum_all <= 8000000) {
        sub3(n, l, r, w);
    }

    else {
        sub45(n, l, r, w);
    }
}