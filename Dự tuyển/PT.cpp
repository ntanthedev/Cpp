#include<bits/stdc++.h>
#define ll long long
const int N = 1e6+9;
using namespace std;
ll a[N], n, gmax, T;
stack<ll>st;
void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    gmax = LLONG_MIN;
    for(int i = n; i >= 1; --i){
        if(a[i] > gmax){
            st.push(a[i]);
            gmax = a[i];
        }
    }
    //cout<<st.size()<<'\n';
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("PT.inp","r",stdin);
    freopen("PT.out","w",stdout);
    cin >> T;
    while(T--)
        solve();
}
