//created in 2024-09-04-20.10.46 in Code::Blocks 20.03
#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, m, ans = 0, cnt = 0, d = 0;
int w[N][N], h[N], L[N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);


    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> w[i][j];

    memset(h, 0, sizeof h);

    for(int i = 1; i <= m; i++) {
        stack<int> st;
        d = 0;
        for(int j = 1; j <= n; j++) {
            if(w[i][j])
                h[j] = (!w[i - 1][j] ? h[j] + 1 : 1);
            else
                h[j] = 0;

            while(!st.empty() && h[st.top()] >= h[j])
                st.pop();

           L[j] = (st.empty() ? 0 : st.top());
           st.push(j);
        }

        while(!st.empty()) st.pop();

        for(int j = n; j >= 1; j--) {
            while(!st.empty() && h[st.top()] >= h[j])
                st.pop();

            int r = (st.empty() ? n + 1 : st.top());
            int res = h[j] * (r - L[j] - 1);
            cnt += (ans == res);
            d += (ans == res);
            if(d == ans)
                cnt -= ans - 1;
            if(res > ans)
                d = 1, cnt = 1, ans = res;
            st.push(j);
        }
        cout << ans << " " << cnt << '\n';
    }

    cout << ans << " " << cnt;
}
