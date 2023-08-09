#include<bits/stdc++.h>

#define fo(a, b, c) for(int a = b; a <= c; ++a)

const long long N = 1e6+9;
using namespace std;

typedef long long ll;

int n, Q, a[N];


void solve() {
    
}

#define task "DQUERY"
int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin >> n;
    fo(i, 1, n)
        cin >> a[i];
    cin >> Q;
    while(Q--) {
        int l, r;
        cin >> l >> r;
    }
    solve();
}