//problem "b"
//created in 14:44:27 - Sun 21/07/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, ans = 0LL;
    cin >> m >> n;
    vector<vector<int> > a(m + 2, vector<int>(n + 2)), h(m + 2, vector<int>(n + 2, 0));

    char tmp;
    for(int i = 1; i <= m; i++) 
        for(int j = 1; j <= n; j++) 
            cin >> tmp, 
            a[i][j] = (tmp == '.' ? 1 : 0);
        
    vector<int> s, l(n + 2);

    // for(int i = 1; i <= m; i++, cout << '\n') 
    //     for(int j = 1; j <= n; j++)
    //         cout << a[i][j] << " ";

    for(int i = 1; i <= m; i++) { 
        s.clear();
        for(int j = 1; j <= n; j++) {
            h[i][j] = (a[i][j] ? h[i - 1][j] + 1 : 0);
            while(!s.empty() && h[i][s.back()] >= h[i][j])
                s.pop_back();
            l[j] = (s.empty() ? 0 : s.back()); 
            s.push_back(j);
        }
        s.clear();
        for(int j = n; j >= 1; --j) {
            while(!s.empty() && h[i][s.back()] >= h[i][j])
                s.pop_back();
            int r = (s.empty() ? n + 1 : s.back());

            ans = max(ans, (r - l[j] - 1) * h[i][j]);
            // if(i == m)
            // cout << i << " " << j << " " << h[i][j] << " " << l[j] << " " << r << '\n';
            s.push_back(j);
        }
    }

    
    // for(int i = 1; i <= m; i++, cout << '\n') 
    //     for(int j = 1; j <= n; j++)
    //         cout << h[i][j] << " ";

    cout << ans;
}