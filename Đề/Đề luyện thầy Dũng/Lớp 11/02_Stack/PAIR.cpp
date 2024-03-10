#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define pell pair<ll,ll>
#define pei pair<int,int>
#define dpe pair<ll,pe>
#define x first
#define y second
const ll maxn=5e5+10;
int n,a[maxn];
ll res;
stack<int>s,st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if(fopen("PAIRS.INP","r"))
    {
        freopen("PAIRS.INP","r",stdin);
        freopen("PAIRS.OUT","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        while(!s.empty()&&a[s.top()]<a[i])
        {
            res++;
            s.pop();
        }
        if(!s.empty())
        {
            res++;
            if(a[i]==a[s.top()]) continue;
        }
        s.push(i);
    }
    cout<<res;
}

