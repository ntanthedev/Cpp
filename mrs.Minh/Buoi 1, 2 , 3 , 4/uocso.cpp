#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll x;
stack<ll>st;
void slove(ll n)
{
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            cout<<i<<" ";
            if(n%(n/i) == 0 && (n/i) != i)
                st.push(n/i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("uocso.inp","r",stdin);
    freopen("uocso.out","w",stdout);
    cin>>x;
    slove(x);
}