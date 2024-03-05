#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define fi first 
#define se second 
#define int int64_t

using namespace std;

vector<int> bina(int x) {
    vector<int> y;
    int d = 0;
    while(x != 0) {
        if(x % 2 != 0)
            y.push_back(d);
        x /= 2;
        d++;
    }
    return y;
}

void solve() {
    int n, s, ans = 0;
    cin >> s >> n;
    vector<int> a(n), s2, s3;
    map<int, int> m;
    for(auto &i : a) {
        cin >> i;
        // i = log2(i);
        m[log2(i)]++;
    }
    
    s2 = bina(s);
    // cout << "s2: " ;
    // for(auto i : s2)
    //     cout << i << " "; cout << '\n';
    for(auto &i : s2) {
        for(auto &j : m) {
            if(j.fi < i && j.se > 1) {
                m[j.fi+1] += j.se/2;
                j.se %= 2;
            }
            if(j.fi >= i)
                break;
        }
        if(m[i]) {
            m[i]--;
            continue;
        }
        else 
            s3.push_back(i);
    }
    reverse(all(s3));
    // cout << "s3: ";
    // for(auto i : s3)
    //     cout << i << " "; cout << '\n';
    set<int> s1;
    // cout << "s1: ";
    for(auto &i : m) {
        if(i.se != 0) {
            s1.insert(i.fi);
            // cout << i.fi << " ";
        }
    }
    // cout << '\n';
    for(auto &i : s3) {
        while(!m[i]) {
            auto t = s1.upper_bound(i);
            if(t == s1.end()) {
                return cout << -1, void();
            }
            m[*t]--;
            if(!m[*t-1]) {
                s1.insert(*t-1);
                s1.erase(t);
            }
            m[*t-1] += 2;
            // cout << *t << " ";
            ans++;
        }
    }
    cout << ans;    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test_case;
    for(cin >> test_case; test_case--; cout << '\n') {
        solve();
    }
}