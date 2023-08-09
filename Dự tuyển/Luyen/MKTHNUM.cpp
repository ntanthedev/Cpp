#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e5+9;
using namespace std;

typedef long long ll;

int n, m, a[N];

void build(int x, int l, int r, vector<pair<int, int>> &a, vector<int> tree[]) {
    if(l == r) {
        tree[x].push_back(a[l].second);
        return;
    }
}


void solve() {
    
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen("MKTHNUM.inp","r")){
        freopen("MKTHNUM.inp","r",stdin);
        freopen("MKTHNUM.out","w",stdout);
    }
    cin >> n >> m;
    fo(i, 1, n)
        cin >> a[i];
    solve();
}