#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second 
typedef long long ll;
vector<ll>f[239],vis(239),dpp(239);
set<ll>save[239];
vector<vector<ll>>dp(239,vector<ll>(239));
void dfs(ll u,vector<ll>&a,ll&ans)
{
    vis[u]=1;
    for(auto v:f[u])
    {
        bool o=true;
        if(save[v].empty())
        {
            save[v].insert(u);
            save[u].insert(v);
            dpp[u]=dp[u-1][v-1];
            dpp[v]=dp[v-1][u-1];
        }
        else
        {
            for(auto i:f[v])
            {
                if(i==u) continue;
                if(!save[u].count(i)) o=false;
            }
            if(o)
            {
                ll x=dpp[u];
                for(auto i:f[v])
                {
                    x+=dp[i-1][v];
                }
                if(x>dpp[v]) 
                {
                    dpp[v]=x;
                    save[v].insert()
                }
                for(auto i:f[v])
                {
                    if(dpp[i]<x)
                    {
                        dpp[i]=x;
                        st[i]=st[u];
                    }
                }
            }
        }
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    bool o=true;
    for(ll i=1;i<=m;i++)
    {
         ll x,y,z;
         cin>>x>>y>>z;
         dp[x-1][y-1]=z;
         dp[y-1][x-1]=z;
         if(z!=1 && z!=(-1e9)) o=false;
    }
    if(n<=20)
    {
        vector<ll>ans;
        ll anss=-1e17;
        for(ll i=0;i<(1<<(n));i++)
        {
            vector<ll>save;
            ll savee=0;
            for(ll j=0;j<n;j++)
            {
                if((1<<j)&i)
                {
                    save.push_back(j);
                }
            }
            //for(auto j:save) cout<<j<<" ";
            //cout<<'\n';
            for(ll j=0;j<save.size();j++)
            {
                for(ll k=j+1;k<save.size();k++)
                {
                    savee+=dp[save[j]][save[k]];
                }
            }
            if(savee>anss)
            {
                anss=savee;
                ans=save;
            }
        }
        cout<<ans.size()<<'\n';
        for(auto i:ans) cout<<i+1<<" ";
    }
    else if(o)
    {
        for(ll i=1;i<=n;i++)
        {
            for(ll j=i+1;j<=n;j++)
            {
                if(dp[i-1][j-1]>=0)
                {
                    f[i].push_back(j);
                    f[j].push_back(i);
                }
            }
        }
        ll anss=0;
        vector<ll>ans;
        for(ll i=1;i<=n;i++)
        {
            if(!vis[i]) dfs(i,ans,anss);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}