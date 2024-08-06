//problem "CAMERA"
//created in 08:31:31 - Tue 06/08/2024

#include<bits/stdc++.h>

#define int int64_t

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i].first;
    char tmp;
    for(int i = 0; i < n; i++) { 
        cin >> tmp; 
        a[i].second = (tmp == 'W' ? 0 : 1);
    }
    vector<int> st, f(n, 1);
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        if(a[i].second) continue;
        while(!st.empty() && a[st.back()].first <= a[i].first) { 
            ans[i] += f[st.back()];
            f[i] += (st.back() == a[i].first) * f[st.back()];
            st.pop_back();
        }
        st.push_back(i);
    }

    for(int i = n; i >= 0; --i) {
        if(a[i].second) continue;
        while(!st.empty() && a[st.back()].first <= a[i].first) { 
            ans[i] += f[st.back()];
            f[i] += (st.back() == a[i].first) * f[st.back()];
            st.pop_back();
        }
        st.push_back(i);
    }
}