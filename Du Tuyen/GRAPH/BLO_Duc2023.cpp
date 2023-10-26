#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ox;
#define fi first
#define se second
const long long MaxN = 1e6;

namespace Solve
{	
	int n, m;
	vector<int> p[1000001];
	vector<ox> Bri;
	ox a[1000001];
	vector<int> Node;
	long long num[1000001], low[1000001], ok[1000001];
	long long Times, res;
	map<long long, int> cnt;
	long long vis[1000001];
	long long siz[1000001];
	long long f[1000001];

	void DFS(int u)
	{
		num[u] = Times++;
	    low[u] = 1e9;
	    int sz = 0;
	    siz[u] = 1;
	    vector<int> Node;

	    for(auto c: p[u])
	    {
	    	if(num[c] == -1)
	    	{
	    		sz++;
	    		DFS(c);
	    		siz[u] += siz[c];
	    		
	    		low[u] = min(low[u], low[c]);
	    		if(num[u] <= low[c])
	    		{
	    			Node.push_back(c);
	    			if(u != 1 || (u == 1 && sz > 1)) ok[u] = 1;
	    		}
	    	}
	    	else
	    	{
	    		low[u] = min(low[u], num[c]);
	    	}
	    }

	    long long Total = 0;
	    for(auto c: Node)
	    {
	    	Total += siz[c];

	    	f[u] += siz[c] * (n - 1 - siz[c]);
	    }

	    f[u] += Total * (n - 1 - Total);
	}

	void ReadInput()
	{
		cin >> n >> m;

		for(int i = 1; i <= m; i++)
		{
			int u, v;
			cin >> u >> v;

			a[i] = {u, v};

			p[u].push_back(v);
			p[v].push_back(u);
		}
	}

	void solve()
	{
		memset(num, -1, sizeof num);

	    DFS(1);

	    for(int i = 1; i <= n; i++)
	    {
	    	if(ok[i])
	    	{
	    		cout << 2 * (n - 1) + f[i] << '\n'; 
	    	}
	    	else
	    	{
	    		cout << 2 * (n - 1) << '\n';
	    	}
	    }
	}
}
int main()
{
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("BLO.inp","r",stdin);
	freopen("BLO.out","w",stdout);

	Solve::ReadInput();
	Solve::solve();
}