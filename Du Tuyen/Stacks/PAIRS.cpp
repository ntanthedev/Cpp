#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, a[N], x, cnt = 0;
stack<ll>st;
void solve(){    
    cin>>a[1];
    st.push(1);
    for(int i = 2; i <= n; i++){
        cin>>a[i];
        ll gmax = a[st.top()] - 1;
        while(!st.empty() && (a[st.top()] < a[i] && a[st.top()] > gmax)){
            st.pop();
            cnt++;
            gmax = a[st.top()];
        }
        if(!st.empty())
            cnt++;
        while(!st.empty() && a[st.top()] == a[i])
            st.pop();
        st.push(i);
    }
    cout<<cnt;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    // freopen("PAIRS.inp","r",stdin);
    // freopen("PAIRS.out","w",stdout);
    cin>>n;
    solve();
}

for(int i = 1; i <= n; i++) {
    cin >> a[i];
    for(int j = 1; j <)
}