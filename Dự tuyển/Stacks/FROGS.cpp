#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long 
const long long R = 1e9+7;
const long long N = 1e6+9;
ll n, v[N], h[N], j[N];
ll top, S[N];
void slove(){
    top = 0; S[top] = 1000001;
    for(int i = n-1; i >= 0; --i){
        while(S[top] <= h[i])
            top--;
        S[++top] = h[i];
        if(top <= j[i])
            v[i] = -1;
        else
            v[i] = S[top-j[i]];
    }
    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    freopen("FROGS.inp","r",stdin);
    freopen("FROGS.out","w",stdout);
    cin>>n; h[n] = -1;
    for(int i = 0; i < n; i++)
        cin>>h[i];
    for(int i = 0; i < n; i++)
        cin>>j[i];
    slove();
}