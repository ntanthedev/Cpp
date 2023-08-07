#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)
#define eb emplace_back

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

int n, m, k, t = 0, t1 = 0, t2 = 0;
vector<int> adj[N];

struct pt {
    int par, x, v;
};
pt f[N]; 

int find_set(int x) {
    return f[x].par < 0 ? x : f[x].par = find_set(f[x].par);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(f[a].par < f[b].par)
            swap(a, b);
        f[a].par += f[b].par;
        f[a].x += f[b].x;
        f[a].v += f[b].v;
        f[b].par = a;
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("YG.inp","r")) {
        freopen("YG.inp","r",stdin);
        freopen("YG.out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        f[i].par = -1;
        if(i <= k) 
            f[i].v = 1, f[i].x = 0;
        else 
            f[i].x = 1, f[i].v = 0;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        ++t;
        cin >> u >> v;
        union_sets(u, v);
        if((f[u].v == k || f[v].v == k) && t1 == 0)
            t1 = t;
        if((f[u].x == n-k || f[v].x == n-k) && t2 == 0)
            t2 = t;
    }
    
    cout << t1 << " " << t2;
}