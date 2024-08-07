//problem "CAMERA"
//created in 08:31:31 - Tue 06/08/2024

#include<bits/stdc++.h>

// #define int int64_t

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
    int res = 0;
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.back()].first <= a[i].first) { 
            ans[i] += f[st.back()] * (!a[i].second);            
            f[i] += (a[st.back()].first == a[i].first) * f[st.back()];            
            res -= f[st.back()];          
            st.pop_back();
        }
        if(!a[i].second)
            ans[i] += res;
        st.push_back(i);
        res += f[i];
    }
    st.clear();
    fill(f.begin(), f.end(), 1);
    res = 0;
    for(int i = n - 1; i >= 0; --i) {
        while(!st.empty() && a[st.back()].first <= a[i].first) { 
            ans[i] += f[st.back()] * (a[i].second);
            f[i] += (a[st.back()].first == a[i].first) * f[st.back()];
            res -= f[st.back()];
            st.pop_back();
        }
        if(a[i].second) 
            ans[i] += res;
        st.push_back(i);
        res += f[i];
    }
    for(auto i : ans) 
        cout << i << " ";

}
/*
5 
1 2 2 3 1 
EEWWE 
*/
