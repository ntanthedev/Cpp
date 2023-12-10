#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    int n, x, ans = 0;
    map<int, int> M;
    stack<int> st;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        while(!st.empty() && x > st.top()) {
            M[st.top()]--;
            st.pop();
            ans++;
        }
        if(!st.empty()) {
            if(st.top() == x)
                ans += M[x] + (st.size() > M[x]);
            else
                ans++; 
        }
        st.push(x);
        M[x]++;
    }
    cout << ans;
}