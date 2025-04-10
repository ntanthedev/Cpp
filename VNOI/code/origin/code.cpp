#include<bits/stdc++.h>
using namespace std;
map<int,int> d;
set<int> res;
queue<int> q ;
void bfs(int start)
{
  d[start]=1;
  q.push(start);
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for(int i = 1 ;i<=sqrt(u);i++)
    {
      if(u%i==0&&!d[(i-1)*(u/i+1)])
      {
        res.insert((i-1)*(u/i+1));
        q.push((i-1)*(u/i+1));
        d[(i-1)*(u/i+1)]=1;
      }
    }
  }
}
  main ()
{
     ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
    freopen("code.inp","r",stdin);
    freopen("code.out","w",stdout);

  int n ;
  cin>>n;
  bfs(n);
  cout<<res.size()<<endl;
  for(auto x:res) cout<<x<<" ";
}
