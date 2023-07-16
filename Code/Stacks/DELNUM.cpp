#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double 
const long long MOD = 1e9+7;
const long long N = 1e6+9;
ll n, x1, x2, x3;
stack<ll>st;
void solve(){
    for(int i = 3; i <= n; i++){
        cin>>x3;
        while(st.empty() > 1 && st.top() < x3){
            x2 = st.top();
            st.pop();
            x1 = st.top();
        }
        if(x2 > x1){
            st.push(x2);
            break;
        }
    }
    st.push(x3);
    cout<<st.empty()-1;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("DELNUM.inp","r",stdin);
    freopen("DELNUM.out","w",stdout);
    cin>>n;
    cin>>x1>>x2;
    st.push(LLONG_MIN);
    st.push(x1);
    st.push(x2);
    solve();
}