#include<bits/stdc++.h>

#define int long long
const int N = 505;

using namespace std;

int n;
string s;
vector<pair<char, char>> ans;

void sub1() {
    s = ' ' + s;
    if(s[2] == s[3]) {
        if(s[1] != s[2])
            ans.push_back({s[1], s[2]});
    }
    else {
        if(s[1] == s[2]) {
            for(int i = 'A'; i <= 'C'; i++)
                if(s[2] != i && s[3] != i) {
                    ans.push_back({s[1], i});
                    s[1] = i;
                    break;
                }
            ans.push_back({s[2], s[3]});
            ans.push_back({s[1], s[3]});
        }
        else {
            ans.push_back({s[2], s[3]});
            ans.push_back({s[1], s[3]});
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << ans[i].second << '\n';
}
//chuyen w dia tu x -> y voi trung gian la z
void bt(int x, int y, int z, int w) {
    if(w == 1) {
        ans.push_back({x + 'A', y + 'A'});
        return;
    }
    bt(x, z, y, w - 1);
    ans.push_back({x + 'A', y + 'A'});
    bt(z, y, x, w - 1);
}

void sub2() {
    bt(0, 2, 1, n);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); ++i)
        cout << ans[i].first << ans[i].second << '\n';
}

void sub3() {
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #define _ "HAPPY"
    freopen(_".inp","r",stdin);
    freopen(_".out","w",stdout);

    cin >> n >> s;
    vector<int> cnt(3, 0);
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }
    if(n == 3)
        sub1();
    else if(cnt[0] == n)
        sub2();
    else 
        sub3();
}
