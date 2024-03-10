#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll temp, a[N], n, cnt = 0;
stack<ll>st;

void solve(){
    for(int i = 2; i < n; i++){
        if(a[i] < st.top() && a[i] < a[i+1]){
            cnt++;
            //i++;
        }
        else
            st.push(a[i]);
    }
    st.push(a[n]);
    ll s = st.size();
    ll t = max(s, n-cnt);
    cout<<t;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DELNUM.inp","r",stdin);
    freopen("DELNUM.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    st.push(a[1]);
    solve();
}