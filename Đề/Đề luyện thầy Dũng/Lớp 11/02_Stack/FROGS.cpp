#include <bits/stdc++.h>
using namespace std;
#define FASTIO                    \
ios_base::sync_with_stdio(false); \
cin.tie(0);                       \
cout.tie(0);
#define ll long long
const ll N = 1e6+9;
ll n, v[N], h[N], j[N], top, S[N];
void slove(){
    top = 0;
    S[top] = 1000001;
    for(int i = n-1; i >= 0; --i){
        while(S[top] <= h[i])
            top--;
        S[++top] = h[i];
        if(top <= j[i])
            v[i] = -1;
        else
            v[i] = S[top - j[i]];
    }
    for(int i = 0; i < n; i++)
        cout<<v[i]<<" ";
}
int main()
{
    FASTIO;
    freopen("frogs.INP","r",stdin);
    freopen("frogs.OUT","w",stdout);
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>h[i];
    for(int i = 0; i < n; i++)
        cin>>j[i];
    slove();
}
