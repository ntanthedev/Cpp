#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
stack<int>st;
ll l[N], n, a[N];
void input(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
}
void slove(){
    for(int i = 1; i <= n; i++){
        while(!st.empty() && a[st.top()] <= a[i])
            st.pop(); 
        if(st.empty())
            l[i] = 0;
        else
            l[i] = st.top();
        st.push(i);
    }
    for(int i = 1; i <= n; i++){
        cout<<l[i] - 1<<" ";
    }
}
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("lineup.inp","r",stdin);
    freopen("lineup.out","w",stdout);
    input();
    slove();
}