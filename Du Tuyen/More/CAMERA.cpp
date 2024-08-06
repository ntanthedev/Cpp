//problem "CAMERA"
//created in 08:31:31 - Tue 06/08/2024

#include<bits/stdc++.h>

// #define int int64_t

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
#else
#define dbg(x...)
#endif

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

    dbg(a)

    vector<int> st, f(n, 1);
    vector<int> ans(n, 0);
    int res = 0;
    
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.back()].first <= a[i].first) { 
            ans[i] += f[st.back()] * (!a[i].second);
            dbg(i) dbg(st) dbg(f[st.back()]) 
            f[i] += (a[st.back()].first == a[i].first) * f[st.back()];
            dbg(f[i])
            res -= f[st.back()];
            dbg(res)
            st.pop_back();
        }
        if(!a[i].second)
            ans[i] += res;
        dbg(ans[i])
        st.push_back(i);
        res += f[i];
    }
    dbg(ans)
    st.clear();
    fill(f.begin(), f.end(), 1);
    res = 0;
    for(int i = n - 1; i >= 0; --i) {
        while(!st.empty() && a[st.back()].first <= a[i].first) { 
            ans[i] += f[st.back()] * (a[i].second);
            dbg(i) dbg(st) dbg(f[st.back()]) 
            f[i] += (a[st.back()].first == a[i].first) * f[st.back()];
            dbg(f[i])
            res -= f[st.back()];
            dbg(res)
            st.pop_back();
        }
        if(a[i].second) 
            ans[i] += res;
        dbg(ans[i])
        st.push_back(i);
        res += f[i];
    }
    dbg(ans)
    for(auto i : ans) 
        cout << i << " ";

}
/*
5 
1 2 2 3 1 
EEWWE 
*/