#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
stack<int>st;
ll n;
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("coso2.inp","r",stdin);
    freopen("coso2.out","w",stdout);
    cin>>n;
    while(n != 0){
        st.push(n%2);
        n /= 2;
    }
    while (!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    
}