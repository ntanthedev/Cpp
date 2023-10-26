#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;

void slove(){
    string s;
    cin>>s;
    ll n = s.size();
    map<char, int>M;
    M['{'] = 1;
    M['['] = 2;
    M['('] = 3;
    M['}'] = 4;
    M[']'] = 5;
    M[')'] = 6;
    stack<char>st;
    for(int i = 0; i < n; i++){
        if(M[s[i]] > 3)
            if(!st.empty() && M[s[i]] - 3 == M[st.top()])
                st.pop();
            else{
                cout<<"NO"<<'\n';
            }
        else
            st.push(s[i]);
    }
    if(!st.empty()){
        cout<<"NO"<<'\n';
    }
    else
        cout<<"YES"<<'\n';
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("parentheses.inp","r",stdin);
    freopen("parentheses.out","w",stdout);
    ll n;
    cin>>n;
    for(int i = 1; i <= n; i++)
        slove();
}